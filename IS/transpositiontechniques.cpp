#include<bits/stdc++.h>
using namespace std;
map<int ,int>keymap1;
map<int ,int>keymap2;
void setPermutations(string key , int k )
{
   for(int i =0;i<key.size();i++)
   {
     if(k==1)keymap1[key[i]] = i;
     else keymap2[key[i]] = i;
   }
}
string encrypt(string plaintext,string key, int k )
{
    map<int ,int>keymap;
    if(k==1)keymap1;
    else keymap = keymap2;


    int row , col , j;
    col = keymap.size();
    row = plaintext.size()/col;
    if(plaintext.size()%col)
    {
        row++;
    }
    char matrix[row][col];
    //create the matrix
    for(int i =0 , k = 0;i<row ;i++)
    {
        for(int j = 0;j<col;)
        {
            if(plaintext[k] == '\0')
            {
                matrix[i][j] = '*';
                j++;
            }
            else
            {
                matrix[i][j] = plaintext[k];
                j++;
                k++;
            }
        }
    }
    // dipaly the mtrix formed
     for(int i=0;i<row;i++)
    {
        for(int j=0;j<col;j++)
        {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    //encrypt the message by reading column by column
    map<int , int> :: iterator itr;
    string cipherText = "";
    for(itr=keymap.begin();itr!=keymap.end();itr++)
    {
        int j=itr->second;
        for(int i=0;i<row;i++)
        {
            if(isalpha(matrix[i][j]) || matrix[i][j]==' '|| matrix[i][j]=='_')
            cipherText+=matrix[i][j];
        }
    }
    return cipherText;
}
string decrypt(string ciphertext , string key , int k)
{   map<int ,int>keymap;
    if(k==1)keymap=keymap1;
    else keymap=keymap2;
    int row,col,j;
    col=keymap.size();
    row=ciphertext.size()/col;
    if(ciphertext.size()%col)row++;
    char cipherMat[row][col];    
}
int main()
{
    cout<<"Enter the message you want to encrypt:";
    string msg;
    cin>>msg;
    cout<<"Enter the first key:";
    string key1;
    cin>>key1;
    cout<<"Enter the second key:";
    string key2;
    cin>>key2; 
    

    return 0;
}