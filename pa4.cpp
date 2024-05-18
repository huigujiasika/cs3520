#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <utility>
#include <algorithm>
#include <cstring>
#include <iomanip> 
#include <ios>    

using namespace std;

// find the 2D vector size
pair<int, int> findVec2DSize(int num) {
    int vector_dim_length = floor(sqrt(num));
    vector<int> vec2d_size = {vector_dim_length, vector_dim_length};
    int index = 0;
    while (true) {
        int mul = vec2d_size[0] * vec2d_size[1];
        if (mul >= num) {
            break;
        }
        vec2d_size[index++] += 1;
    }   

    pair<int, int> vec2d = make_pair(vec2d_size[0], vec2d_size[1]);
    return vec2d;
}

// find the 3D array size
vector<int> findArray3DSize(int num) {
    int array_dim_length = floor(cbrt(num)); 
    vector<int> array3d_size = {array_dim_length, array_dim_length, array_dim_length};
    int index = 0;
    while (true) {
        int mul = array3d_size[0] * array3d_size[1] * array3d_size[2];
        if (mul >= num) {
            break;
        }
        array3d_size[index++] += 1;
    }

    return array3d_size;
}

// fill numbers to 2D vector
void fillNumbers(vector<vector<double>> &vec2d, const pair<int, int> &vec2d_size, const vector<double> &numbers) {
    int row_max = vec2d_size.first, col_max = vec2d_size.second;
    int temp = 0;
    for (int row = 0; row < row_max; row++) {
        for (int col = 0; col < col_max; col++) {
            vec2d[row][col] = numbers[temp++];
        }
    }
}

// fill numbers to 3D array
void fillNumbers(double ***array3d, const vector<int> &array3d_size, const vector<double> &numbers) {
    int dim1_max = array3d_size[0], dim2_max = array3d_size[1], dim3_max = array3d_size[2];
    int temp = 0;
    for (int dim1 = 0; dim1 < dim1_max; dim1++) {
        for (int dim2 = 0; dim2 < dim2_max; dim2++) {
            for (int dim3 = 0; dim3 < dim3_max; dim3++) {
                array3d[dim1][dim2][dim3] = numbers[temp++];
            }
        }
    }
}

// write 2D vector to file
void write_2d_vector(const vector<vector<double>>& vec2d, const string& filename, int max_digits, double sum) {
    ofstream outfile(filename);
    outfile << fixed << setprecision(1);    // set precision
    if (outfile.is_open()) {
        outfile << sum << endl;
        for (const auto& row : vec2d) {
            for (const auto& num : row) {
                outfile << left << setw(max_digits + 2) << num << ' ';
            }
            outfile << endl;
        }
        outfile.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// write 3D array to file
void write_3d_array(double ***array3d, vector<int> array3d_size, int max_digits, const string& filename, double sum) {
    ofstream outfile(filename);
    outfile << fixed << setprecision(1);    // set precision

    if (outfile.is_open()) {
        outfile << sum << endl;
        int dim1_max = array3d_size[0], dim2_max = array3d_size[1], dim3_max = array3d_size[2];
        for (int dim1 = 0; dim1 < dim1_max; dim1++) {
            for (int dim2 = 0; dim2 < dim2_max; dim2++) {
                for (int dim3 = 0; dim3 < dim3_max; dim3++) {
                    outfile << left << setw(max_digits + 2) << array3d[dim1][dim2][dim3] << " ";
                }
                outfile << endl;
            }
            outfile << endl;
        } 
        outfile.close();
    } else {
        cout << "Unable to open file: " << filename << endl;
    }
}

// calculate the digits for aligning
int calculateDigits(double num) {
    int num_int = static_cast<int>(num);
    return to_string(num_int).length();
}

int main() {
    vector<string> inputfile_vec = {"input1", "input2", "input3", "input4"};

    for (auto &file_name : inputfile_vec) {
        ifstream infile(file_name + ".txt");
        if (!infile.is_open()) {
            cout << "Unable to open file: " << file_name + ".txt" << endl;
            return 1;
        }

        vector<double> numbers;
        double num, sum = 0.0;
        int max_digits = 0;
        while (infile >> num) {
            int num_length = calculateDigits(num);         // calculate the max digits for aligning
            if (num_length > max_digits) {
                max_digits = num_length;
            }
            numbers.push_back(num);      // read numbers
            sum += num;                  // calculate sum
            infile.ignore();
        }
        infile.close();

        // calculate the size of the vector
        int num_numbers = numbers.size();

        // calculate the size
        pair<int, int> vec2d_size = findVec2DSize(num_numbers);
        vector<int> array3d_size = findArray3DSize(num_numbers);

        // create the 2D vector and initialize
        vector<vector<double>> vec2d(vec2d_size.first, vector<double>(vec2d_size.second, 0.0));

        // create the 3D array and initialize
        double ***array3d = new double** [array3d_size[0]];
        for (int i = 0; i < array3d_size[0]; i++) {
            array3d[i] = new double* [array3d_size[1]];
        }
        for (int i = 0; i < array3d_size[0]; i++) {
            for (int j = 0; j < array3d_size[1]; j++) {
                array3d[i][j] = new double [array3d_size[2]];
            }
        }

        // fill numbers to vec3d and array3d
        fillNumbers(vec2d, vec2d_size, numbers);             
        fillNumbers(array3d, array3d_size, numbers);

        // write the 2D vector to file
        write_2d_vector(vec2d, file_name + "_2DVector.txt", max_digits, sum);
        // write the 3D array to file
        write_3d_array(array3d, array3d_size, max_digits, file_name + "_3DArray.txt", sum);

        // print the sum
        cout << "Sum of all numbers (" << file_name + ".txt)" << " : " << sum << endl;
    }

    return 0;
}

/* pseudocode : pa4 
 * Input  : numbers from this file
 * Output : 2D vector of appropriate size and 3D array to store these values
 * 
 * open the input file and input the numbers from inputfile to vector<double> numbers
 * calculate the values of all the numbers to sum
 * num_numbers = numbers.size 
 * get the suitable vec2d_size and get the suitbale array3d_size
 * Initialize 2d vector by vec2d_size
 * Initialize 3d array by array3d_size
 * fill numbers of 2d vector by numbers and vec2d_size 
 * fill numbers of 3d array by numbers and array3d_size
 * write_2d_vector
 * write_3d_array
*/