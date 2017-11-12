//
//  relations.cpp
//  Relations
//
//  Created by Alvaro Nicoli on 11/11/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include "relations.hpp"
#include <iostream>

using namespace std;

namespace relations {
    bool is_reflexive(vector<vector<bool>> adjacency_matrix)
    {
        for (int i = 0; i < adjacency_matrix.size(); ++i)
        {
            if (!adjacency_matrix[i][i])
            {
                return false;
            }
        }
        
        return true;
    }
    
    bool is_antisymmetric(vector<vector<bool>> adjacency_matrix)
    {
        for (int i = 0; i < adjacency_matrix.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (adjacency_matrix[i][j] == adjacency_matrix[j][i])
                {
                    return false;
                }
            }
        }
        
        return true;
    }
    
    bool is_transitive(vector<vector<bool>> adjacency_matrix)
    {
        vector<vector<bool>> trns_clsre = trans_closure(adjacency_matrix);
        
        // Remove ones from the diagonal since they will always be zeroed out in the transitive closure
        for (int i = 0; i < adjacency_matrix.size(); ++i)
        {
            adjacency_matrix[i][i] = false;
        }
        
        return trns_clsre == adjacency_matrix;
    }
    
    vector<vector<bool>> trans_closure(vector<vector<bool>> adjacency_matrix)
    {
        vector<vector<bool>> ret_val = adjacency_matrix;
        
        for (int i = 0; i < adjacency_matrix.size(); ++i)
        {
            ret_val[i][i] = false;
        }
        
        for (int k = 0; k < ret_val.size(); ++k)
        {
            for (int i = 0; i < ret_val.size(); ++i)
            {
                for (int j = 0; j < ret_val[i].size(); ++j)
                {
                    int dt = ret_val[i][k] + ret_val[k][j];
                    if (ret_val[i][j] > dt)
                    {
                        ret_val[i][j] = dt;
                    }
                }
            }
        }
        
        return ret_val;
    }
    
    bool is_order(vector<vector<bool>> adjacency_matrix)
    {
        return is_reflexive(adjacency_matrix) && is_antisymmetric(adjacency_matrix) && is_transitive(adjacency_matrix);
    }
    
    vector<string> antichains(vector<vector<bool>> adjacency_matrix)
    {
        vector<string> ret_val;
        vector<vector<bool>> trnspose = transpose(adjacency_matrix);
        
        for (int i = 0; i < trnspose.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (trnspose[i][j] == trnspose[j][i])
                {
                    string str;
                    str = static_cast<char>(i + 65);
                    str += " <-> ";
                    str += static_cast<char>(j + 65);
                    
                    ret_val.push_back(str);
                }
            }
        }
        
        return ret_val;
    }
    
    vector<vector<bool>> transpose(vector<vector<bool>> adjacency_matrix)
    {
        vector<vector<bool>> ret_val = adjacency_matrix;
        
        for (int i = 0; i < ret_val.size(); ++i)
        {
            for (int j = 0; j < ret_val[i].size(); ++j)
            {
                ret_val[i][j] = !ret_val[i][j];
            }
        }
        
        return ret_val;
    }
    
    vector<vector<bool>> original_from_hasse(vector<vector<bool>> adjacency_matrix)
    {
        vector<vector<bool>> ret_val = adjacency_matrix;
        
        // undo reflexive reduction
        for (int i = 0; i < ret_val.size(); ++i)
        {
            ret_val[i][i] = true;
        }
        
        // undo transitive reduction
        for (int j = 0; j < ret_val.size(); ++j)
        {
            for (int i = 0; i < ret_val.size(); ++i)
            {
                if (ret_val[i][j])
                {
                    for (int k = 0; k < ret_val.size(); ++k)
                    {
                        if (ret_val[j][k])
                        {
                            ret_val[i][k] = true;
                        }
                    }
                }
            }
        }
        
        return ret_val;
    }
    
    vector<vector<bool>> hasse_from_original(vector<vector<bool>> adjacency_matrix)
    {
        if (!is_order(adjacency_matrix)) {
            throw "Bad relation";
        }
        
        vector<vector<bool>> ret_val = adjacency_matrix;
        
        // reflexive reduction
        for (int i = 0; i < ret_val.size(); ++i)
        {
            ret_val[i][i] = false;
        }
        
        // transitive reduction
        for (int j = 0; j < ret_val.size(); ++j)
        {
            for (int i = 0; i < ret_val.size(); ++i)
            {
                if (ret_val[i][j])
                {
                    for (int k = 0; k < ret_val.size(); ++k)
                    {
                        if (ret_val[j][k])
                        {
                            ret_val[i][k] = false;
                        }
                    }
                }
            }
        }
        
        return ret_val;
    }
}
