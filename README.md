# MAP

Problema celor 8 turnuri: să se scrie un program care plasează 8 turnuri pe tabla de șah, fără ca acestea să se atace reciproc.

Aici va fi documentatia pentru acest proiect :

In primul rand am gandil la a doua variant ade cod, in care dupa executare va fi si prezentarea grafica de tablou de sah, asa dupa research am gasit nisti librarii care pot sa folosesc pentru asta si am ajuns sa fac cu <Windows.h> - Windows SDK Extention. Am pus fisier cu prezentarea grafica dar nu am reusit sa fac imaginea docker din cauza ca nu am Extention pentru aceasta libraria.

 In rest, mai jos puteti sa gasiti cod cu comentariile. Imi placut sa lucrez cu Git si Docker, stiu si ca in viitorul apropriat intanesc cu ei mai des.


#include <iostream>
#include <vector>
using namespace std;

Această secțiune include fișierele de antet necesare pentru operațiile de intrare/ieșire (iostream) și manipularea array-urilor dinamice (vector). Instrucțiunea using namespace std; este folosită pentru a simplifica codul, permitând utilizarea identificatorilor standard C++ fără a specifica spațiul de nume.

const int n = 8;

Definește un întreg constant n cu valoarea 8, reprezentând dimensiunea tablei de șah și numărul de regine.

bool isSafe(const vector<vector<int>>& board, int row, int col) 
    // Funcție pentru a verifica dacă plasarea unei regine într-o poziție specifică este sigură.
    // Returnează true dacă este sigur, false în caz contrar.

Funcția isSafe verifică dacă este sigur să plasați o regină într-o anumită poziție pe tabla de șah. Ea ia în considerare coloana curentă, diagonală stângă și diagonală dreaptă pentru a se asigura că alte regine nu amenință noua poziționare.

bool solveNQueens(vector<vector<int>>& board, int col) 
    // Funcție recursivă pentru a rezolva problema reginelor N folosind backtracking.
    // Returnează true dacă o soluție este găsită, false în caz contrar.

Funcția solveNQueens este un algoritm de backtracking recursiv pentru a găsi o soluție la problema reginelor N. Ea încearcă să plaseze regine în fiecare rând al coloanei curente, revenind dacă o plasare în siguranță nu este posibilă.

void print(const vector<vector<int>>& board) {
    // Funcție pentru a afișa configurarea tablei de șah.
Documentație:

Funcția print afișează starea curentă a tablei de șah, indicând pozițiile reginelor (1 pentru regină, 0 pentru pătrat gol).

int main() {
    // Funcția principală unde începe execuția programului.

Funcția main este punctul de intrare al programului.

    vector<vector<int>> board(n, vector<int>(n, 0));

Creează o tablă de șah goală reprezentată printr-un vector 2D (board) cu dimensiunile n x n, inițializată cu zerouri.

    if (!solveNQueens(board, 0)) {
        cout << "Fără soluții" << endl;
    } else {
        print(board);
    }

    return 0;
}

Invocă funcția solveNQueens pentru a încerca să găsească o soluție. Dacă este găsită o soluție, afișează configurarea tablei; în caz contrar, afișează "Fără soluții."
