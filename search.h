//
// Created by Alexandr on 08.06.2015.
//

#ifndef TP_SEARCH_H
#define TP_SEARCH_H

#include <ostream>
#include "Matrix.h"

using namespace std;

bool input(matrix *a,ifstream& input_file, ofstream& output_file )
{
    BYTE n,m,i,j;
    int val;

    input_file >> n;
    input_file >> m;

    if(n>0 && m>0)
    {

        MakeEmptyMatrix(a,n,m);
        for(i=1; i< n; i++)
        {
            goto_line(a,i);
            input_file >> val;
            ChangeValue(a,val);
            for (j = 1; j < m ; j++)
            {
                goto_nextColumn(a);
                input_file >> val;
                ChangeValue(a,val);
            }
        }
        addLog("Input matrix",a,output_file);
        input_file.close();
        cout << "Matrix succssefuly created" << endl;
        output_file << "Matrix succssefuly created" << endl;
        output_file.close();
        return true;
    }
    else
    {
        cout <<"Incorrect data or input file is empry"<<endl;
        output_file << "Incorrect data or input file is empry"<<endl;
        output_file.close();
        return false;
    }
}

void FreeMem(matrix *a)
{
    if (EmptyCheck(a))
        cout << "Memory is empry" << endl;
    else
    {
        while (a->n != 0)
        {
            DeleteLine(a);
        }
        while (a->m !=0)
            a->m --;
        cout << "Memory cleaned" << endl;
    }
}

void ChangeElem(matrix *a, ofstream& output_file)
{
    BYTE k,i,j;
    int val;

    if (EmptyCheck(a))
        cout << "Memory is empry" << endl;
    else
    {
        cout << "Line: ";
        cin >> i;
        cout << "\nColomn: ";
        cin >> j;

        if(i > a->n || j > a->m || j <=0 || i<=0)
            cout << "Incorrect index" << endl;
        else
        {
            goto_line(a,i);
            for(k=1; k < j; k++ )
                goto_nextColumn(a);

                cout << "Value: ";
                cin >> val;
                ChangeValue(a,val);
                addLog("Matrix elem value was changed on  "+ val,a,output_file);
                cout << "Value was changed" << endl;
        }
    }
}

void ChangeSize(matrix *a, ofstream& output_file)
{
    BYTE n,m;

    cout << "New size is: ";
    cin >> n >> m;
    if(n<=0 || m <=0)
        cout << "incorrect size" <<endl;
    else
    {
        addLog("Size was changed",a,output_file);
        if(EmptyCheck(a))
        MakeEmptyMatrix(a,n,m);
        else
        {

            if(n > a->n)
            {
                while(n != a->n)
                    AddLine(a);
            }
            if (n < a->n)
            {
                while (n != a->n)
                    DeleteLine(a);
            }
            if(m > a->m)
            {
                while(m != a->m)
                    AddColumn(a);
            }
            if (m < a->m)
            {
                while (m != a->m)
                    DeleteColomn(a);
            }
            cout << "Size was changed"<< endl;
        }
    }

}

#endif //TP_SEARCH_H
