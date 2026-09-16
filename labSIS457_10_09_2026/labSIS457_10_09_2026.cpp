#include <iostream>
#include <string>

using namespace std;

class Rook
{
private:
    int row;
    int column;
    bool isBlack;

    bool validateMovement(int newRow, int newCol)
    {
        if (newRow == row || newCol == column)
        {
            return true;
        }

        return false;
    }

public:
    Rook(bool color, int initialRow, int initialColumn)
    {
        isBlack = color;
        row = initialRow;
        column = initialColumn;
    }

    int getRow()
    {
        return row;
    }

    int getColumn()
    {
        return column;
    }

    bool getIsBlack()
    {
        return isBlack;
    }
    void setRow(int newRow)
    {
        row = newRow;
    }

    void setColumn(int newColumn)
    {
        column = newColumn;
    }

    void setIsBlack(bool color)
    {
        isBlack = color;
    }

    void move(int newRow, int newCol)
    {
        if (newRow < 1 || newRow > 8 ||
            newCol < 1 || newCol > 8)
        {
            cout << "Error: posicion fuera del tablero." << endl;
            return;
        }
        if (validateMovement(newRow, newCol))
        {
            row = newRow;
            column = newCol;

            cout << "Movimiento realizado correctamente." << endl;
        }
        else
        {
            cout << "Error: la torre solo puede moverse "
                << "horizontal o verticalmente." << endl;
        }
    }

    string draw()
    {
        if (isBlack)
        {
            return "[**]";
        }

        return "[TT]";
    }

    void printState()
    {
        cout << draw();

        if (isBlack)
        {
            cout << " Black";
        }
        else
        {
            cout << " White";
        }

        cout << " at Row: " << row
            << ", Col: " << column << endl;
    }
};


int main()
{
    Rook torre(false, 1, 1);

    cout << "ESTADO INICIAL" << endl;
    torre.printState();

    cout << "\nMoviendo torre a fila 1, columna 5..." << endl;
    torre.move(1, 5);
    torre.printState();

    cout << "\nIntentando mover torre a fila 3, columna 7..." << endl;
    torre.move(3, 7);
    torre.printState();

    cout << "\nMoviendo torre a fila 4, columna 5..." << endl;
    torre.move(4, 5);
    torre.printState();

    return 0;
}