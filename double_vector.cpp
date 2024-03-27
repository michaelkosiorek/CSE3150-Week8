#include <iostream>
#include <cmath>
#include "double_vector.h"

using namespace std;

double square(const double & d){
    return d*d;
}

double dot_product(const double_vector & one, const double_vector & two) {
    return one.x * two.x + one.y * two.y;
}

double magnitude(const double_vector & my_vector) {
    return sqrt(square(my_vector.x) + square(my_vector.y));
};

double cosine_distance(const double_vector & one, const double_vector & two) {
    double dot_prod = dot_product(one,two);
    double one_magnitude = magnitude(one);
    double two_magnitude = magnitude(two);

    double d = dot_prod/(one_magnitude*two_magnitude);
    if (d > 1.0) 
        d = 1.0;
    if (d < -1.0)
        d = -1.0;

    return 1 - d;
}

vector<double_vector> read_vector_file(const string &filename) {
    ifstream file(filename);  // Open the file
    string line;
    vector<double_vector> double_vec_vec;  // Vector to store the pairs

    if (file.is_open()) {
        int x, y;
        while (getline(file, line)) {  // Read each line
            istringstream iss(line);
            iss >> x >> y;  // Extract two numbers from the line
            double_vector double_vec_inst;
            double_vec_inst.x = x;
            double_vec_inst.y = y;
            // cout << double_vec_inst.x << " " << double_vec_inst.y << endl;
            double_vec_vec.push_back(double_vec_inst);
        }
        file.close();
    } else {
        cout << "File opening error." << endl;
    }
    return double_vec_vec;
}


vector<vector_pair> make_vec_pairs(const vector<double_vector> &vectors_original) {
    int vectors_original_size = vectors_original.size();
    vector<vector_pair> vec_pairs;
    
    for (int i = 0; i < vectors_original_size - 1; i++) {
        for (int j = i + 1; j < vectors_original_size; j++) {
            vector_pair new_pair(vectors_original[i], vectors_original[j], cosine_distance(vectors_original[i], vectors_original[j]));
            vec_pairs.push_back(new_pair);
        }
    }
    return vec_pairs;
}

bool compare_cos_dist(const vector_pair& a, const vector_pair& b) {
    return a.vec_cos_distance > b.vec_cos_distance;
}