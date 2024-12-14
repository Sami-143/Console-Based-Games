#include <iostream>
using namespace std;
main()
{
    int c;
    int count = 0;
    int num;
    string a;
    cout << "ENTER" << endl;
    getline(cin, a);
    num = a.length();
    for (int i = 0; i < num; i++)
    {
        for (int j = i + 1; j < num; j++)
        {
            if (a[i] == a[j])
            {
                count++;
                break;
            }
            if (a[i] == ' ')
            {
                break;
            }
        }
    }
    cout << count;
}


// #include <iostream>
// #include <string>
// #include <unordered_set>

// using namespace std;

// bool is_rotatable(const string& word) {
//     unordered_set<char> rotatable_letters = {'H', 'I', 'N', 'O', 'S', 'X', 'Z', 'M', 'W'};
//     for (char letter : word) {
//         if (rotatable_letters.count(letter) == 0) {
//             return false;
//         }
//     }
//     return true;
// }

// int rotated_words(const string& txt) {
//     unordered_set<string> unique_rotated_words;
//     string word;
//     for (char c : txt) {
//         if (c == ' ') {
//             if (is_rotatable(word)) {
//                 string rotated_word = "";
//                 for (char letter : word) {
//                     if (letter == 'M') {
//                         rotated_word += 'W';
//                     } else if (letter == 'W') {
//                         rotated_word += 'M';
//                     } else {
//                         rotated_word += letter;
//                     }
//                 }
//                 unique_rotated_words.insert(rotated_word);
//             }
//             word = "";
//         } else {
//             word += c;
//         }
//     }

//     return unique_rotated_words.size();
// }

// int main() {
//     cout << rotated_words("HSSN") << endl; // 1
//     cout << rotated_words("OS IS UPDATED") << endl; // 2
//     cout << rotated_words("MUBASHIR") << endl; // 0
//     return 0;
// }
