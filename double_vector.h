#ifndef _DOUBLE_VECTOR_H_
#define _DOUBLE_VECTOR_H_

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>
#include <sstream>
#include <algorithm>

using namespace std;


struct double_vector {
    double x;
    double y;
    
    double_vector() : x(0.0), y(0.0) {}; // empty
    double_vector(double x, double y) :  x(x), y(y) {}; // def
    double_vector(const double_vector & dv) : x(dv.x), y(dv.y) {}; // cpy
};

struct vector_pair {
    double_vector v1, v2;
    double vec_cos_distance;

    vector_pair() : v1(), v2(), vec_cos_distance() {};
    vector_pair(double_vector v1, double_vector v2, double vec_cos_distance) : v1(v1), v2(v2), vec_cos_distance(vec_cos_distance) {};
    vector_pair(const vector_pair & vp) : v1(vp.v1), v2(vp.v2), vec_cos_distance(vp.vec_cos_distance) {};
};


vector<vector_pair> make_vec_pairs(const vector<double_vector> &vectors);
vector<double_vector> read_vector_file(const string &filename);
double square(const double & d);
double dot_product(const double_vector & one, const double_vector & two) ;
double magnitude(const double_vector & my_vector);
double cosine_distance(const double_vector & one, const double_vector & two);
bool compare_cos_dist(const vector_pair& a, const vector_pair& b);


#endif