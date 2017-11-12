//
//  matrix.cpp
//  Relations
//
//  Created by Alvaro Nicoli on 11/11/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#include "matrix.hpp"

using namespace std;

namespace matrix {
    vector<vector<bool>> matrix_prod(vector<vector<bool>> matrix1, vector<vector<bool>> matrix2)
    {
        vector<vector<bool>> ret_val;
        
        matrix2 = transpose(matrix2);
        
        for (int i = 0; i < matrix1.size(); ++i)
        {
            ret_val.push_back({});
            
            for (int j = 0; j < matrix2.size(); ++j)
            {
                ret_val[i].push_back(vector_prod(matrix1[i], matrix2[j]));
            }
        }
        
        return ret_val;
    }
    
    bool vector_prod(vector<bool> vec1, vector<bool> vec2)
    {
        if (vec1.size() != vec2.size())
        {
            throw "Cannot multiply";
        }
        
        bool ret_val = false;
        
        for (int i = 0; i < vec1.size(); ++i)
        {
            ret_val = ret_val || (vec1[i] && vec2[i]);
        }
        
        return ret_val;
    }
    
    vector<vector<bool>> transpose(vector<vector<bool>> matrix)
    {
        vector<vector<bool>> ret_val = matrix;
        
        for (int i = 0; i < ret_val.size(); ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                bool aux = ret_val[i][j];
                ret_val[i][j] = ret_val[j][i];
                ret_val[j][i] = aux;
            }
        }
        
        return ret_val;
    }
}
