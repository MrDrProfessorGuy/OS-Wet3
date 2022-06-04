#ifndef SORTEDLIST_SORTEDLIST_H
#define SORTEDLIST_SORTEDLIST_H

#include <stdexcept>

#include "QueueManager.h"
    
    
    
    class SortedList;
    
/**************************************************/
/********************* Node *********************/
/**********************************************/

    class Node{
    public:
        enum Type {Head, Tail, Data};
    private:
        Type type;
        const JobEntry data;
        Node* next;
        Node* previus;

        /**
         * constructor for a dummy Node that holds no data
         */
        Node(Type type=Data) :type(), data(), next(nullptr), previus(nullptr){
        
        }
        /**
         * linkNodes: link next and previus pointers of two given nodes in the given order.
         * @tparam T
         * @param first_node
         * @param second_node
         */
        static void linkNodes(Node& first_node, Node& second_node);
    
    public:
        friend class SortedList;
        explicit Node(JobEntry const& node_data, Node* previus_node = nullptr, Node* next_node = nullptr){
            type = Data;
            data = (node_data);
            previus = previus_node;
            next = next_node;
        }
        ~Node(){
        
        }
        Node(const Node&) = delete;
        /**
         * Node<T>::remove - link the previus and next nodes (if exist) and delete the node.
         * @tparam T
         */
        void remove();
    };

    
    void Node::linkNodes(Node& first_node, Node& second_node){
        first_node.next = &second_node;
        second_node.previus = &first_node;
    }


    void Node::remove(){
        Node::linkNodes(*previus, *next);
        delete this;
    }



/*******************************************************/
/********************* SortedList *********************/
/*****************************************************/
    
    class SortedList {
    public:
        class const_iterator;
        SortedList() : size(2){
            Node::linkNodes(head, end_node);
        }
        SortedList(const SortedList& list) : size(2){
            Node::linkNodes(head, end_node);
            const_iterator end_of_list = list.end();
            const_iterator iterator = list.begin();
            try {
                while (iterator != end_of_list){
                    insert(*iterator);
                    iterator++;
                }
            }
            catch (const std::bad_alloc& ) {/// in case one of the new allocations fail
                removeNodes();
                throw ;
            }
        }
        ~SortedList(){
            removeNodes();
        }
        /**
         * Create and return an identical Copy  of the given list
         * @param sortedList
         * @return
         *  sortedList
         */
        SortedList& operator=(const SortedList& sortedList){
            if (this == &sortedList){
                return *this;
            }
            Node tmp_head, current_node;
            SortedList list_copy = SortedList(sortedList); // create a new copy before deleting current data
            
            removeNodes(); // allocation success ==> delete data
            if (list_copy.length() != 0){
                // Link data
                Node* last_node = (list_copy.end_node).previus;
                Node::linkNodes(head, *(list_copy.head.next));
                Node::linkNodes(*(last_node), end_node);
                // Unlink tmp list from data
                Node::linkNodes(list_copy.head, list_copy.end_node);
            }
           
            size = list_copy.size;
            return *this;
        }
        /**
         * insert the given data to the list, keeping the list ordered
         * @param data
         */
        void insert(const T& data){
            Node* new_node = new Node(data);// bad alloc is the caller's problem, can't help in here
            
            Node* current_node = head.next;
            while (current_node != &end_node){
                if (data < *current_node->data){
                    Node* previus = current_node->previus;
                    Node::linkNodes(*previus, *new_node);
                    Node::linkNodes(*new_node, *current_node);
                    size++;
                    return;
                }
                current_node = current_node->next;
            }
            Node* previus = current_node->previus;
            Node::linkNodes(*previus, *new_node);
            Node::linkNodes(*new_node, *current_node);
            size++;
        }
        /**
         * remove the data the given iterator is pointing at
         * @param iterator
         */
        void remove(const const_iterator& iterator){
            const_iterator end_of_list = end();
            if (iterator == end_of_list){
                throw std::out_of_range("");
            }
            Node* to_delete = find(*iterator);
            if (to_delete == nullptr){
                throw std::out_of_range("");
            }
            to_delete->remove();
            size--;
        }
        /**
         * return the number of data elements in the list
         * @return
         */
        int length() const{
            return (size-2);
        }
        /**
         * return const_pointer to the first (smallest) data element
         */
        const_iterator begin() const{
            return ++const_iterator(head);
        }
        /**
         * return const_pointer to the last (biggest) data element
         */
        const_iterator end() const{
            return const_iterator(end_node);
        }
    
       
        SortedList filter(Condition condition) const;
        SortedList apply(JobEntry function(const JobEntry)) const{
            
            SortedList new_list = SortedList();
            const_iterator end_of_list = end();
            const_iterator iterator = begin();
            while (iterator != end_of_list){
                new_list.insert(function(*iterator));
                iterator++;
            }
            return new_list;
        }
    
    private:
        Node head;
        Node end_node;
        int size;
        
        Node* find(const JobEntry& data) const{
            Node* current_node = head.next;
            while (current_node != &end_node){
                // We shouldn't assume T has defined operator==()
                if (!(*current_node->data < data) &&
                    !(data < *current_node->data)){
                    return current_node;
                }
                current_node = current_node->next;
            }
            return nullptr;
        }
        void removeNodes(){
            const_iterator end_of_list = end();
            const_iterator iterator = begin();
            while (iterator != end_of_list){
                remove(iterator);
                iterator = begin();
            }
        }
    };

/***********************************************************/
/********************* const_iterator *********************/
/*********************************************************/

    class SortedList::const_iterator{
        const Node* node;
        
        const_iterator() = delete;
        const_iterator(const Node& node_ptr) : node(&node_ptr){
        }
    
    
    public:
        friend class SortedList;
        const_iterator(const const_iterator&) = default;///remove const?
        const_iterator& operator=(const const_iterator&) = default;
        ~const_iterator() = default;
        const_iterator& operator++(){
            if (node == nullptr){
                throw std::out_of_range("");
            }
            node = node->next; // node->next is null_ptr by default
            return *this;
        }
        const_iterator operator++(int){
            if (node == nullptr){
                throw std::out_of_range("");
            }
            const_iterator tmp_iterator = *this;
            ++(*this);
            return tmp_iterator;
            
        }
        const_iterator& operator--(){
            if (node == nullptr){
                throw std::out_of_range("");
            }
            node = node->previus; // node->previus is null_ptr by default
            return *this;
        }
        const_iterator operator--(int){
            if (node == nullptr){
                throw std::out_of_range("");
            }
            const_iterator tmp_iterator = *this;
            --(*this);
            return tmp_iterator;
        }
        const T& operator*() const{
            if (node == nullptr){
                throw std::out_of_range("");
            }
            return *node->data;
        }
        
        bool operator==(const const_iterator& iterator) const{
            if (iterator.node == nullptr || node == nullptr){
                return false;
            }
            if (node == iterator.node){
                return true;
            }

/*        /// using < in case T has not implemented '==' or '>'
        if (!(*(node->data) < *(iterator.node->data)) &&
            !(*(iterator.node->data) < *(node->data))){
            return true;
        }
        */
            return false;
        }
        bool operator!=(const const_iterator& iterator) const {
            return !(node == iterator.node);
            
        }
    };

/*************************************************************/
/********************* Function Objects *********************/
/***********************************************************/

    SortedList SortedList::filter(Condition condition) const {
        SortedList filtered_list;
        for (typename SortedList<T>::const_iterator iterator = begin(); iterator != end(); ++iterator) {
            if (condition(*iterator)) {
                filtered_list.insert(*iterator);
            }
        }
        return filtered_list;
    }
    
    
    



#endif //SORTEDLIST_SORTEDLIST_H
