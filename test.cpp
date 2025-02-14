#include <iostream>
#include	<vector>

using namespace std;

class Matrix {
	int n;

public:
	vector<vector<int>> mat;
	Matrix(int n) {
		this->n = n;
		mat.resize(n);
		for (int i = 0; i < n; ++i) mat[i].resize(n);
	}

	void Print() {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				cout << mat[i][j] << " ";
			}
			cout << "\n";
		}
	}
	Matrix operator*(const Matrix& a) {
		Matrix tmp(this->n);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					tmp.mat[i][j] += this->mat[i][k] * a.mat[k][j];
				}
				tmp.mat[i][j] %= 1000;
			}
		}
		return tmp;
	}
};

Matrix Pow(const Matrix& a, long long b) {
	if (b == 1) return a;

	Matrix tmp = Pow(a, b / 2);

	if (b % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * a;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(NULL);
	std::cout.tie(NULL);
	
	long long N, B;
	cin >> N >> B;

	Matrix m(N);
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < N; ++j) {
			cin >> m.mat[i][j];
			m.mat[i][j] %= 1000;
		}
	}

	Matrix answer = Pow(m, B);

	answer.Print();
}