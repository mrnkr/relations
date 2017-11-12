//
//  relations.hpp
//  Relations
//
//  Created by Alvaro Nicoli on 11/11/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef relations_hpp
#define relations_hpp

#include <stdio.h>
#include <string>
#include <vector>

using namespace std;

namespace relations {
    // The adjacency matrix of a reflexive relation has a diagonal full of ones
    bool is_reflexive(vector<vector<bool>> adjacency_matrix);
    
    // Antisymmetric relations can be spotted by their adjacency matrix being symmetric
    bool is_antisymmetric(vector<vector<bool>> adjacency_matrix);
    
    // A relations adjacency matrix is equal to its transitive closure when it is transitive
    bool is_transitive(vector<vector<bool>> adjacency_matrix);
    
    // The transitive closure of a relation is the smallest transitive relation contained in the
    // original relation. Hence, the adjacency matrix will have edges removed to reach that
    // transitive closure.
    vector<vector<bool>> trans_closure(vector<vector<bool>> adjacency_matrix);
    
    // A relation is an order if it is reflexive, antisymmetric and transitive at the same time
    bool is_order(vector<vector<bool>> adjacency_matrix);
    
    // Returns all the double edges of the opposite relation to the one represented by the
    // passed adjacency matrix, which are called antichains (or not, didnt check the actual
    // english name) in a human readable format (like a beautiful -h in a disgusting bash command)
    vector<string> antichains(vector<vector<bool>> adjacency_matrix);
    
    // Generates the opposite relation to the one represented by the passed adjacency matrix.
    vector<vector<bool>> transpose(vector<vector<bool>> adjacency_matrix);
    
    // Takes an adjacency matrix that represents a Hasse diagram and returns the adjacency
    // matrix that represents the original order relation.
    // This function makes the adjacency matrix be both reflexive and transitive by adding
    // all the ones in the diagonal and the shortcuts, hence, having (x,y) and (y,z) it adds
    // (x,z)
    vector<vector<bool>> original_from_hasse(vector<vector<bool>> adjacency_matrix);
    
    // Hasse diagrams represent order relations without the need to make
    // reflexivity or transitivity evident, since what matters is the reachability
    // from point a to point b
    // This function - if passed an order relation - returns the adjacency matrix representing
    // its Hasse diagram, hence, it performs a reflexive reduction and a transitive reduction
    vector<vector<bool>> hasse_from_original(vector<vector<bool>> adjacency_matrix);
}

#endif /* relations_hpp */
