#include<iostream>
#include<sstream>
#include<fstream>
#include<cstring>
using namespace std;

int binary(int n)
{
    if(n==0)
        return 0;
    return (n%2+10*binary(n/2));
}
int cnt=0;
int main()
{
    ifstream f1;
    ofstream of("output.txt");
    string  what,inst,s,s1,s2,s3,s4,s5;
    int r[14];
    int n1,n2,n3,n4,n5,k;
    int E=0,GT=0;
   int count=0;
   int reg[1000];

    f1.open("input.txt");
    int j=0;
    repeat:
    while(getline(f1,s))
    {
        istringstream w(s);
         w>>what;
         //cout<<"what="<<what;
         //cout<<"\nInstruction="<<inst;
       if(what==".encode")
       {
            w>>inst;
           /* **************************** MOV ********************************************* */
             if(inst=="mov")
             {
               w>>s1;
               w>>s2;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op
               istringstream(s2)>>k;//imm
               if(k>0)
               {
                   r[n1]=k;
                  // cout<<"k="<<k;

                int b1=binary(k);
                int b2=binary(n1);
                int arr1[18],arr2[4];
                for(int i=0;i<4;i++)
                    arr2[i]=0;
                for(int i=0;i<18;i++)
                    arr1[i]=0;
                int k1=17,k2=3;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
               if(j==0)
               {

                of<<"01001 ";
                of<<"1 ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];

                of<<" "<<"**** ";
                for(int i=0;i<18;i++)
                    of<<arr1[i];
                 of<<"\n";
               }
               }

               else
               {
                r[n1]=r[n2];

                 int b1=binary(n2);
                int b2=binary(n1);
                int arr1[18],arr2[4];
                for(int i=0;i<4;i++)
                    arr2[i]=0;
                for(int i=0;i<18;i++)
                    arr1[i]=0;
                int k1=17,k2=3;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
              if(j==0){
                of<<"01001 ";
                of<<"0 ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];

                of<<" "<<"**** ";
                for(int i=0;i<18;i++)
                    of<<arr1[i];
                 of<<"\n";
              }

             }
           }
          /* **************************** ADD ********************************************* */
            if(inst=="add")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0)
               {

                r[n1]=r[n2]+k;
                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
             if(j==0){
                of<<"00000 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else
               {

                r[n1]=r[n2]+r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;

                }
                for(int i=0;i<18;i++)
                    arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
              if(j==0){
                of<<"00000 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<17;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }

            }//add

            /* **************************** SUB ********************************************* */
            if(inst=="sub")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=r[n2]-k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00001 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else
               {

                r[n1]=r[n2]-r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[4];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;

                }
                for(int i=0;i<18;i++)
                 arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                if(j==0){

                of<<"00001 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
              }//sub
            /* **************************** MUL ********************************************* */
            if(inst=="mul")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0)
               {
                r[n1]=r[n2]*k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                  if(j==0){

                        //cout<<"hello";
                       // cout<<"\ncount="<<cnt<<endl;
                of<<"00010 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else
               {
                r[n1]=r[n2]*r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }
                for(int i=0;i<17;i++)
                {
                    arr3[i]=0;
                }
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
              if(j==0){
                       // cout<<"\ncount="<<cnt<<endl;
                        cnt++;
                of<<"00010 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//mul

            /* **************************** DIV ********************************************* */
            if(inst=="div")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0)
               {
                r[n1]=r[n2]/k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00011 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else
               {
                r[n1]=r[n2]/r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
              if(j==0){
                of<<"00011 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//div

            /* **************************** MOD ********************************************* */
            if(inst=="mod")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0)
               {

                r[n1]=r[n2]%k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00100 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else
               {

                r[n1]=r[n2]%r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;

                }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00100 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//mod

            /* **************************** AND ********************************************* */
            if(inst=="and")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=r[n2]&k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00110 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else{
                r[n1]=r[n2]&r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }

                for(int i=0;i<18;i++)
                arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00110 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
                }
            }//and

            /* **************************** OR ********************************************* */
            if(inst=="or")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=r[n2]|k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                if(j==0){
                of<<"00111 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else{
                r[n1]=r[n2]|r[n3];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;

                }
                for(int i=0;i<4;i++)
                    arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"00111 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//or

            /* **************************** NOT ********************************************* */
            if(inst=="not")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=~k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                 if(j==0){
                of<<"01000 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else{
                r[n1]=~r[n2];

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }
                for(int i=0;i<18;i++)
                    arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"01000 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//not

            /* **************************** LSL ********************************************* */
            if(inst=="lsl")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=r[n2]<<k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                 if(j==0){
                of<<"01010 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else{
                r[n1]=r[n2]<<r[n3];
                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                    arr3[i]=0;
                }
                for(int i=0;i<4;i++)
                    arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){
                of<<"01010 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}

                ///////////
               }
            }//lsl
            /* **************************** LSR ********************************************* */
            if(inst=="lsr")
            {
               w>>s1;
               w>>s2;
               w>>s3;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s3.substr(1,(s3.length()-1)))>>n3;//op 2
               istringstream(s3)>>k;//immediate value
               if(k>0){
                r[n1]=r[n2]>>k;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(k);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                   {
                       arr1[i]=0;
                       arr2[i]=0;
                   }
                for(int i=0;i<18;i++)
                    arr3[i]=0;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                if(j==0){
                of<<"01011 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
              }
                ///////////
               else{
                r[n1]=r[n2]>>r[n3];
                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int k1=3,k2=3,k3=17;
                int arr1[4],arr2[4],arr3[18];
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;

                }
                for(int i=0;i<4;i++)
                arr3[i]=0;

                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
               if(j==0){

                of<<"01011 ";
                of<<"0 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr3[i];
                of<<"\n";}
               }
                ///////////
            }//lsr

            /* **************************** CMP ********************************************* */

            if(inst=="cmp")
            {
               w>>s1;
               w>>s2;
               istringstream(s1.substr(1,(s1.length()-1)))>>n1;//destination
               istringstream(s2.substr(1,(s2.length()-1)))>>n2;//op 1
               istringstream(s2)>>k;//immediate value
               if(k>=0)
                {
                   if(r[n1]>k)
                    GT=1;
                   if(r[n1]==k)
                    E=1;
                ///encoding
                int b1=binary(k);
                int b2=binary(n1);
                int arr1[18],arr2[4];
                for(int i=0;i<4;i++)
                    arr2[i]=0;
                for(int i=0;i<18;i++)
                    arr1[i]=0;
                int k1=17,k2=3;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
               if(j==0)
               {

                of<<"00101 ";
                of<<"1 ";

                of<<"**** ";
                for(int i=0;i<4;i++)
                    of<<arr2[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr1[i];
                 of<<"\n";
               }
            }
               else
                {
                   if(r[n1]>r[n2])
                    GT=1;
                   if(r[n1]==r[n2])
                    E=1;


                    ///encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int arr2[18],arr1[4];
                for(int i=0;i<4;i++)
                    arr1[i]=0;
                for(int i=0;i<18;i++)
                    arr2[i]=0;
                int k1=3,k2=17;
                while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
               if(j==0)
               {
                of<<"00101 ";
                of<<"0 ";

                of<<"**** ";
                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr2[i];
                 of<<"\n";
               }
            }
                //cout<<"E="<<E<<endl<<"GT="<<GT;
            }
            //cmp
            //*****************STORE**************
            if(inst=="st")
            {
                w>>s1;
                w>>s2;
                w>>s3>>s3;
                istringstream(s1.substr(1,(s1.length()-1)))>>n1;
                istringstream(s2.substr(0,s1.length()))>>n2;
                istringstream(s3.substr(1,(s1.length()-1)))>>n3;
                reg[n2+n3]=r[n1];
                //cout<<reg[n2+n3]<<endl;

                //encoding
                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int arr1[4],arr2[18],arr3[4];
                int k1=3,k2=17,k3=3;
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }
                for(int i=0;i<18;i++)
                {
                    arr3[i]=0;
                }

                 while(b1!=0)//dest
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)//imm
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)//r[n]
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                if(j==0){
                of<<"01111 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr3[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr2[i];
                of<<"\n";}

                ////

            }//st
            //*****************LOAD**************
            if(inst=="ld")
            {
                w>>s1;
                w>>s2;
                w>>s3>>s3;
                istringstream(s1.substr(1,(s1.length()-1)))>>n1;
                istringstream(s2.substr(0,s1.length()))>>n2;
                istringstream(s3.substr(1,(s1.length()-1)))>>n3;
                r[n1]=reg[n2+n3];
                //cout<<reg[n2+n3]<<endl;

                //encoding

                int b1=binary(n1);
                int b2=binary(n2);
                int b3=binary(n3);
                int arr1[4],arr2[4],arr3[18];
                int k1=3,k2=17,k3=3;
                for(int i=0;i<4;i++)
                {
                    arr1[i]=0;
                    arr2[i]=0;
                }
                for(int i=0;i<18;i++)
                {
                    arr3[i]=0;
                }

                 while(b1!=0)
                {
                   arr1[k1]=b1%10;
                   b1=b1/10;
                   k1--;
                }
                while(b2!=0)
                {
                   arr2[k2]=b2%10;
                   b2=b2/10;
                   k2--;
                }
                while(b3!=0)
                {
                   arr3[k3]=b3%10;
                   b3=b3/10;
                   k3--;
                }
                if(j==0){
                of<<"01111 ";
                of<<"1 ";

                for(int i=0;i<4;i++)
                    of<<arr1[i];
                of<<" ";
                for(int i=0;i<4;i++)
                    of<<arr3[i];
                of<<" ";
                for(int i=0;i<18;i++)
                    of<<arr2[i];
                of<<"\n";}

                ////

            }//ld

            /////////////////////////   BRANCHING////////////////////////

            /****   b   ***/
            if(inst=="b")
            {

             w>>s1;//s1=label name
              if(j==0)
             of<<"10010\n";
             j++;
             string d=":";
             s1.append(d);
             f1.seekg(0,ios::beg);
               while(getline(f1,s))
               {
                   istringstream w(s);
                   w>>s2>>s2;
                   if(s2==s1)
                   {
                       goto repeat;
                   }

               }

            }////b

            /****   beq   ***/
            if(inst=="beq")
            {

             w>>s1;//s1=label name
             if(j==0)
             {
             of<<"10000\n";
              j++;
             }

             string d=":";
             s1.append(d);
            if(E==1)
           {
               E=0,GT=0;
             f1.seekg(0,ios::beg);
             while(getline(f1,s))
               {
                   istringstream w(s);
                   w>>s2>>s2;
                   if(s2==s1)
                   {
                       goto repeat;
                   }
               }
            }

            }////beq

             /****   bgt  ***/
            if(inst=="bgt")
            {

             w>>s1;//s1=label name
             if(j==0)
             of<<"10001\n";
              j++;
             string d=":";
             s1.append(d);
            if(GT==1)
            {
              E=0,GT=0;
             f1.seekg(0,ios::beg);
             while(getline(f1,s))
               {
                   istringstream w(s);
                   w>>s2>>s2;
                   if(s2==s1)
                   {
                       goto repeat;
                   }
               }
            }

            }////beq



            /////////////////////////////////////////////////

       }//.encode
     /* ********************PRINT*************************/
       if(what==".print")
       {
           w>>s4;
           istringstream(s4.substr(1,(s4.length()-1)))>>n4;
           cout<<endl<<r[n4]<<endl;
           //encoding
           // of<<binary(r[n4]);
            of<<"r"<<n4<<" = "<<r[n4];
            of<<"\n";
           ///////

         }//print
               // what="NULL";
          //j++;
     }//while loop"
    //}//for loop


    return 0;
}
