#include "double_vector.h"

std::ostream& operator<<(std::ostream& os, const vector<vector_pair>& vec) {
    for (int i=0; i < vec.size(); i++) {
        os << vec[i].v1.x << ", " << vec[i].v1.y << " and " <<  vec[i].v2.x << ", " << vec[i].v2.y << " --> " << vec[i].vec_cos_distance << endl;
    }
    return os;
}

int main() {

    string file_name = "double_vectors.txt";
    vector<double_vector> all_vectors = read_vector_file(file_name);

    /*
    for (int i=0; i < all_vectors.size(); i++) {
        cout << all_vectors[i].x << " " << all_vectors[i].y << endl;
    }
    */

    vector<vector_pair> vector_pairs = make_vec_pairs(all_vectors);

    cout << "Before: " << endl << vector_pairs << endl;

    sort(vector_pairs.begin(), vector_pairs.end(), [](const vector_pair &v1, const vector_pair &v2) -> bool {
            return v1.vec_cos_distance > v2.vec_cos_distance;
        }
    );

    cout << "After: " << endl << vector_pairs << endl;

    return 0;
}