#include <bits/stdc++.h>
#include "arreglo.h"

using namespace std;


enum class NodeType { File, Directory };

class FileNode{

    private:
        string name;
        NodeType type;
        arreglo_lista<FileNode*> children;
        FileNode* parent = nullptr;

    public:
        // FileNode(string name, NodeType type, FileNode* parent) : name{name}, type{type}, parent{parent} {}  // constructor en caso de que se inicialize con el padre 
        FileNode(string name, NodeType type) : name{name} , type{type} {}

        string getName() const { return name; }
        NodeType getType() const { return type; }
        const arreglo_lista<FileNode*>& getChildren() const { return children; }
        FileNode* getParent() const { return parent; }
        void setParent(FileNode* parent) { this->parent = parent; }
        void addChild(FileNode* child) { 
            child->setParent(this);  // se asigna el padre al hijo
            children.push_final(child); // se agrega el hijo a la lista de hijos
        }

        ~FileNode(){
            for (int i = 0; i < children.size(); i++)
                delete children[i];
            delete parent;
        }

};


int main() {

    FileNode* rootNode = new FileNode("root", NodeType::Directory);
    FileNode* node1 = new FileNode("node1", NodeType::Directory);
    FileNode* file1 = new FileNode("file1", NodeType::File);
    node1->addChild(file1);
    rootNode->addChild(node1);
    FileNode node( "node1", NodeType::Directory);
    FileNode node2( "node2", NodeType::Directory);
    node.addChild(&node2);

    cout << "Padre de node1: " << node1->getParent()->getName() <<endl;
    


    return EXIT_SUCCESS;
}