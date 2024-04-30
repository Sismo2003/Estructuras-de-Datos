#ifndef FILE_SYSTEM_MANAGEMENT_NODE_H
#define FILE_SYSTEM_MANAGEMENT_NODE_H

#include <bits/stdc++.h>
class Node {
private:
    std::string value;
    Node* left_Node;
    Node* right_Node;
public:
    Node(std::string val){
        value = val;
        left_Node = nullptr;
        right_Node = nullptr;
    };
    Node() : value(""), left_Node(nullptr), right_Node(nullptr) {}
    ~Node() {
        delete left_Node;
        delete right_Node;
    }

    Node(const Node& other) : value(other.value), left_Node(nullptr), right_Node(nullptr) {
        if (other.left_Node)
            left_Node = new Node(*other.left_Node);
        if (other.right_Node)
            right_Node = new Node(*other.right_Node);
    }

    Node& operator=(const Node& other) {
        if (this != &other) {
            value = other.value;
            if (other.left_Node) {
                if (!left_Node) left_Node = new Node(*other.left_Node);
                else *left_Node = *other.left_Node;
            } else {
                delete left_Node;
                left_Node = nullptr;
            }
            if (other.right_Node) {
                if (!right_Node) right_Node = new Node(*other.right_Node);
                else *right_Node = *other.right_Node;
            } else {
                delete right_Node;
                right_Node = nullptr;
            }
        }
        return *this;
    }


    void setNode(Node* newNode,char side ){
        if(newNode != nullptr){
            if(side == 'l'){
                left_Node = newNode;
            }
            else if(side == 'r'){
                right_Node = newNode;
            }else{
                throw runtime_error("setNode atribute side not valid try again!");
            }
        }
        else{
            throw runtime_error("try not to set a NULL value to a Node!");
        }
    };

    string getValue(){
        return value;
    };
    Node* getNode(char side){
        if(side == 'l'){
            if(left_Node != nullptr) return left_Node;
            else throw runtime_error("Not a value for this side of the node!");
        }else if (side == 'r'){
            if(right_Node != nullptr) return right_Node;
            else throw runtime_error("Not a value for this side of the node!");
        }else{
            throw runtime_error("getNode atribute side not valid try again!");
        }
    };
    bool existingNode(char side){
        if(side == 'l'){
            if(left_Node != nullptr) return true;
            else return false;
        }else if (side == 'r'){
            if(right_Node != nullptr) return true;
            else return false;
        }else{
            throw runtime_error("getNode atribute side not valid try again!");
        }

    };
    bool delete_rigth_node(){
        if (right_Node != nullptr){
            delete right_Node;
            return true;
        }
        else return false;
    }
    bool delete_left_node(){
        if (left_Node != nullptr){
            delete left_Node;
            return true;
        }
        else return false;
    }

};



#endif //FILE_SYSTEM_MANAGEMENT_NODE_H


