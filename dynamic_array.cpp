//
// Created by Claudia Steiner on 27.06.24.
//
class DynamicArray {
private:
    int* array; // statisches Array als Backbone
    int length; // Anzahl der Elemente im Array

public:
    DynamicArray(); // Konstruktor
    ~DynamicArray(); // Destruktor
    int get(int index); // Zugriff auf Element
    void add(int value); // Hinzufügen eines Elements
    int size(); // Rückgabe der Länge des Arrays
};

