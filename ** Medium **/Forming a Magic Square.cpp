#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);
vector<string> split(const string &);

int vis[10];
int ans = 100;

bool isMagicSquare(vector<vector<int>> s) {
    bool pass = true;
    int sum = s[0][0] + s[0][1] + s[0][2];
    for (int i = 0; i < 3; i ++) pass = min(pass, s[i][0] + s[i][1] + s[i][2] == sum && s[0][i] + s[1][i] + s[2][i] == sum);
    pass = min(pass, s[0][0] + s[1][1] + s[2][2] == sum && s[0][2] + s[1][1] + s[2][0] == sum);
    return pass;
}

void dfs(vector<vector<int>> s, int vis[10], int idx, int cost) {
    if (idx == 9) {
        if (isMagicSquare(s)) ans = min(ans, cost);
        return;
    }
    
    for (int i = 1; i <= 9; i ++) {
        if (!vis[i]) {
            vis[i] = true;
            int temp = s[idx / 3][idx % 3];
            s[idx / 3][idx % 3] = i;
            dfs(s, vis, idx + 1, cost + abs(temp - i));
            s[idx / 3][idx % 3] = temp;
            vis[i] = false;
        }
    }
}

/*
 * Complete the 'formingMagicSquare' function below.
 *
 * The function is expected to return an INTEGER.
 * The function accepts 2D_INTEGER_ARRAY s as parameter.
 */

int formingMagicSquare(vector<vector<int>> s) {
    dfs(s, vis, 0, 0);
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    vector<vector<int>> s(3);

    for (int i = 0; i < 3; i++) {
        s[i].resize(3);

        string s_row_temp_temp;
        getline(cin, s_row_temp_temp);

        vector<string> s_row_temp = split(rtrim(s_row_temp_temp));

        for (int j = 0; j < 3; j++) {
            int s_row_item = stoi(s_row_temp[j]);

            s[i][j] = s_row_item;
        }
    }

    int result = formingMagicSquare(s);

    fout << result << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

vector<string> split(const string &str) {
    vector<string> tokens;

    string::size_type start = 0;
    string::size_type end = 0;

    while ((end = str.find(" ", start)) != string::npos) {
        tokens.push_back(str.substr(start, end - start));

        start = end + 1;
    }

    tokens.push_back(str.substr(start));

    return tokens;
}
