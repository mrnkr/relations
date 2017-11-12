//
//  matrix.hpp
//  Relations
//
//  Created by Alvaro Nicoli on 11/11/17.
//  Copyright © 2017 Mr.NKR. All rights reserved.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdio.h>
#include <vector>

using namespace std;

namespace matrix {
    vector<vector<bool>> matrix_prod(vector<vector<bool>> matrix1, vector<vector<bool>> matrix2);
    bool vector_prod(vector<bool> vec1, vector<bool> vec2);
    vector<vector<bool>> transpose(vector<vector<bool>> matrix);
}

#endif /* matrix_hpp */
