#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include "doctest.h"

#include "double_vector.h"


TEST_CASE("double_vec") {
    SUBCASE("cosine distance w/ istelf") {
        double_vector v1, v2;
        v1.x = 3;
        v1.y = 0;
        v2.x = 3;
        v2.y = 0;

        double expected_cosine_distance = 0.0;
        double actual_cosine_distance = cosine_distance(v1, v2);
        CHECK_EQ(actual_cosine_distance, expected_cosine_distance);
    };

    SUBCASE("cosine distance") {
        double_vector v1, v2;
        v1.x = 2;
        v1.y = 0;
        v2.x = 0;
        v2.y = 2;

        double expected_cosine_distance = 1.0;
        double actual_cosine_distance = cosine_distance(v1, v2);
        CHECK_EQ(actual_cosine_distance, expected_cosine_distance);
    };

    SUBCASE("cosine distance") {
        double_vector v1, v2;
        v1.x = 6;
        v1.y = 3;
        v2.x = 3;
        v2.y = 6;

        double expected_cosine_distance = 0.2;
        double actual_cosine_distance = cosine_distance(v1, v2);

        CHECK(actual_cosine_distance < expected_cosine_distance + .001);
        CHECK(actual_cosine_distance > expected_cosine_distance - .001);
    };

    SUBCASE("sort cos distances w/ lambda") {
        // first make 5 assorted vector pairs with
        // distinct cosine distances

        vector_pair vp1(double_vector(3, 3), double_vector(3, 0), .29289);
        vector_pair vp2(double_vector(0, 1), double_vector(3, 1), .68377);
        vector_pair vp3(double_vector(0, 1), double_vector(3, 2), .4453);
        vector_pair vp4(double_vector(0, 3), double_vector(0, 4), 0.0);
        vector_pair vp5(double_vector(0, 3), double_vector(3, 0), 1.0);

        vector<vector_pair> all_pairs;
        all_pairs.push_back(vp1);
        all_pairs.push_back(vp2);
        all_pairs.push_back(vp3);
        all_pairs.push_back(vp4);
        all_pairs.push_back(vp5);

        vector<double> cosine_distances;
        for (int i=0; i<5; i++) {
            cosine_distances.push_back(all_pairs[i].vec_cos_distance);
        }

        bool sorted_before=true;
        for (int j=0; j<4; j++) {
            if (all_pairs[j].vec_cos_distance < all_pairs[j+1].vec_cos_distance) sorted_before = false;
        }
        CHECK_FALSE(sorted_before);

        sort(all_pairs.begin(), all_pairs.end(), [](const vector_pair &v1, const vector_pair &v2) -> bool {
            return v1.vec_cos_distance > v2.vec_cos_distance;
        }
        );

        bool sorted_after=true;
        for (int j=0; j<4; j++) {
            if (all_pairs[j].vec_cos_distance < all_pairs[j+1].vec_cos_distance) sorted_after = false;
        }
        CHECK(sorted_after);
    }
}