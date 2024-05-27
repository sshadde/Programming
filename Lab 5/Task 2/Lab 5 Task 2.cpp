#include <iostream>
#include <string>

using namespace std;

// Структура, представляющая информацию об автобусе
struct BusInfo {
    int busNumber;
    string driverName;
    int routeNumber;
    bool isInPark; // Флаг, указывающий на то, находится ли автобус в парке

    // Конструктор для удобства инициализации
    BusInfo(int number, const string& driver, int route, bool inPark)
        : busNumber(number), driverName(driver), routeNumber(route), isInPark(inPark) {}
};

// Узел бинарного дерева
template<typename T>
struct TreeNode {
    T data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(const T& value)
        : data(value), left(nullptr), right(nullptr) {}
};

// Класс бинарного дерева
template<typename T>
class BinaryTree {
private:
    TreeNode<T>* root;

    // Вспомогательная функция для рекурсивного вывода дерева
    void inorderTraversal(TreeNode<T>* node) {
        if (node == nullptr)
            return;
        inorderTraversal(node->left);
        cout << "Bus Number: " << node->data.busNumber << ", Driver: " << node->data.driverName
            << ", Route: " << node->data.routeNumber << ", Location: " << (node->data.isInPark ? "Park" : "Route") << endl;
        inorderTraversal(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    // Вставка нового узла в дерево
    void insert(const T& value) {
        root = insertHelper(root, value);
    }

    // Вспомогательная функция для рекурсивной вставки узла
    TreeNode<T>* insertHelper(TreeNode<T>* node, const T& value) {
        if (node == nullptr)
            return new TreeNode<T>(value);
        if (value.busNumber < node->data.busNumber)
            node->left = insertHelper(node->left, value);
        else
            node->right = insertHelper(node->right, value);
        return node;
    }

    // Вывод всех автобусов в парке
    void printBusesInPark() {
        cout << "Buses in the Park:" << endl;
        printBusesInParkHelper(root);
    }

    // Вывод всех автобусов на маршруте
    void printBusesOnRoute() {
        cout << "Buses on Route:" << endl;
        printBusesOnRouteHelper(root);
    }

    // Пометить автобус как находящийся на маршруте
    void setBusOnRoute(int busNumber) {
        setBusLocationHelper(root, busNumber, false);
    }

    // Пометить автобус как находящийся в парке
    void setBusInPark(int busNumber) {
        setBusLocationHelper(root, busNumber, true);
    }

private:
    // Вспомогательная функция для рекурсивного вывода автобусов в парке
    void printBusesInParkHelper(TreeNode<T>* node) {
        if (node == nullptr)
            return;
        printBusesInParkHelper(node->left);
        if (node->data.isInPark)
            cout << "Bus Number: " << node->data.busNumber << ", Driver: " << node->data.driverName
            << ", Route: " << node->data.routeNumber << endl;
        printBusesInParkHelper(node->right);
    }

    // Вспомогательная функция для рекурсивного вывода автобусов на маршруте
    void printBusesOnRouteHelper(TreeNode<T>* node) {
        if (node == nullptr)
            return;
        printBusesOnRouteHelper(node->left);
        if (!node->data.isInPark)
            cout << "Bus Number: " << node->data.busNumber << ", Driver: " << node->data.driverName
            << ", Route: " << node->data.routeNumber << endl;
        printBusesOnRouteHelper(node->right);
    }

    // Вспомогательная функция для установки местоположения автобуса
    void setBusLocationHelper(TreeNode<T>* node, int busNumber, bool isInPark) {
        if (node == nullptr)
            return;
        if (node->data.busNumber == busNumber) {
            node->data.isInPark = isInPark;
            return;
        }
        if (busNumber < node->data.busNumber)
            setBusLocationHelper(node->left, busNumber, isInPark);
        else
            setBusLocationHelper(node->right, busNumber, isInPark);
    }
};

int main() {
    BinaryTree<BusInfo> busTree;

    // Начальное формирование данных о всех автобусах
    busTree.insert(BusInfo(101, "John Doe", 1, true));
    busTree.insert(BusInfo(102, "Jane Smith", 2, true));
    busTree.insert(BusInfo(103, "Michael Johnson", 3, false));
    busTree.insert(BusInfo(104, "Emily Brown", 4, false));

    // При выезде каждого автобуса из парка
    busTree.printBusesInPark(); // Выведет информацию о всех автобусах, находящихся в парке
    cout << "Bus 101 leaves the park." << endl;
    busTree.setBusOnRoute(101); // Установим состояние автобуса 101 на маршруте
    busTree.printBusesInPark(); // Выведет информацию о всех автобусах, находящихся в парке

    // При въезде каждого автобуса в парк
    cout << "Bus 103 enters the park." << endl;
    busTree.setBusInPark(103); // Установим состояние автобуса 103 в парке
    busTree.printBusesInPark(); // Выведет информацию о всех автобусах, находящихся в парке

    return 0;
}
