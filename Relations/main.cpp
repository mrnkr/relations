//
//  main.cpp
//  Relations
//
//  Created by Alvaro Nicoli on 11/11/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include <iostream>
#include <vector>
#include "relations.hpp"

using namespace std;
using namespace relations;

int main(int argc, const char * argv[]) {
    vector<vector<bool>> adjacency_matrix = {
        {true, false, false},
        {true, false, true},
        {false, false, true}
    };
    
    cout << "Working with:" << endl;
    
    for (int i = 0; i < adjacency_matrix.size(); ++i)
    {
        for (int j = 0; j < adjacency_matrix[i].size(); ++j)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << "" << endl;
    }
    
    cout << "Is reflexive? " << is_reflexive(adjacency_matrix) << endl;
    cout << "Is antisymmetric? " << is_antisymmetric(adjacency_matrix) << endl;
    cout << "Is transitive? " << is_transitive(adjacency_matrix) << endl;
    cout << "Is an order? " << is_order(adjacency_matrix) << endl;
    
    vector<string> antichainz = antichains(adjacency_matrix);
    
    if (antichainz.size() > 0)
    {
        cout << "Antichains" << endl;
    }
    
    for (int i = 0; i < antichainz.size(); ++i)
    {
        cout << antichainz[i] << endl;
    }
    
    adjacency_matrix = {
        {true, false, false},
        {true, true, true},
        {true, false, true}
    };
    
    cout << "\n\nWorking with:" << endl;
    
    for (int i = 0; i < adjacency_matrix.size(); ++i)
    {
        for (int j = 0; j < adjacency_matrix[i].size(); ++j)
        {
            cout << adjacency_matrix[i][j] << " ";
        }
        cout << "" << endl;
    }
    
    cout << "Hasse coming from original" << endl;
    vector<vector<bool>> hasse = hasse_from_original(adjacency_matrix);
    
    for (int i = 0; i < hasse.size(); ++i)
    {
        for (int j = 0; j < hasse[i].size(); ++j)
        {
            cout << hasse[i][j] << " ";
        }
        cout << "" << endl;
    }
    
    cout << "Original relation coming from Hasse" << endl;
    vector<vector<bool>> original = original_from_hasse(hasse);
    
    for (int i = 0; i < original.size(); ++i)
    {
        for (int j = 0; j < original[i].size(); ++j)
        {
            cout << original[i][j] << " ";
        }
        cout << "" << endl;
    }
    
    return 0;
}
