/*
Team:
1) Pradeep Kumar Nalluri , 15XJ1A0533 , pradeep15142@mechyd.ac.in
2) Bontha Sravan Kumar Reddy , 15XJ1A0511 , bonthasravan@gmail.com
3) Garaga Sai Chand , 15XJ1A0515 , chand15066@mechyd.ac.in
*/

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include"FinalDOC.c"
void main(){
  struct abx{
    float** a;
    float* b;
    float* x;
  };
  struct matrix{
    float** a;
  };
  struct vector{
    float* v;
  };
  printf("\t\t*****************************CS204 Project*****************************\t\t\n");
  printf("Please Choose from the following options\n");
  printf("Enter 1 for Equation Solving\n");
  printf("Enter 2 for norms Solving\n");
  int pk;
  scanf("%d",&pk);
  if(pk==1){
    printf("Enter 1 for Direct Methods\n");
    printf("Enter 2 for Iterative Methods\n");
    int dmim;
    scanf("%d",&dmim);
    if(dmim==1){
      printf("Enter 1 for GaussElimination\n");
      printf("Enter 2 for Dollittle Method\n");
      printf("Enter 3 for Cholesky Method\n");
      int gcd;
      scanf("%d",&gcd);
      if(gcd==1){
        int s1,s2,i,j,n;
        printf("Give the Number of Rows:");
        scanf("%d",&s1);
        printf("Give the Number of Coloumns:");
        scanf("%d",&s2);
        n=s1;
        if(s1==s2){
          struct abx gea;
          gea.a=genrn(s1,s2+1);
          gea.b=genrv(s1);
          gea.x=genrv(s1);
          printf("\nEnter the co-efficients of the equations :\n\n") ;//Matrix A
          for(i = 0 ; i < s1 ; i++){
            for(j = 0 ; j < s1 ; j++){
              printf("Enter the element in a[%d][%d] position: ", i + 1, j + 1) ;
              scanf("%f", &gea.a[i][j]) ;
            }
            printf("Enter the element in b[%d] position:", i + 1) ;//matrix b
            scanf("%f", &gea.a[i][n]) ;
          }
          float detk= det(s1,s2,gea.a);
          printf("det:%f",detk);
          if(detk==0){
            printf("Give a Non Singular Matrix\n");
          }else{
          GaussElimination(s1,gea.a,gea.x);
          printf("\nThe result is :\n") ;
          for(i = 0 ; i < s1 ; i++){
           printf("\nx[%d] = %f", i + 1,gea.x[i]);
         }
         free(gea.a);
         free(gea.b);
         free(gea.x);
       }
      }else{
        printf("Give a square Matrix\n");
      }
      }else if(gcd==2){
        int s1,s2;
        printf("Give the Number of Rows:");
        scanf("%d",&s1);
        printf("Give the Number of Coloumns:");
        scanf("%d",&s2);
        if(s1==s2){
          struct abx gea;
          gea.a=gen(s1,s2);
          gea.b=genv(s1);
          gea.x=genrv(s1);
          float** L=genrn(s1,s2);
          float** U=genrn(s1,s2);
          printf("Give the B Matrix\n");
          float* Y=genrv(s1);
          dolildecomp(s1,s2,gea.a,L,U,Y,gea.b,gea.x);
          int i,j;
          for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
              printf("%f\t",L[i][j]);
            }printf("\n");
          }printf("\n\n\n");
          for(int i=0;i<s1;i++){
            for(int j=0;j<s2;j++){
              printf("%f\t",U[i][j]);
            }printf("\n");
          }printf("\n\n\n");

        for(i=0;i<s1;i++){
          printf("The root is:%f\n",gea.x[i]);
        }
        //Freeing the allocated Memmory
        free(gea.a);
        free(gea.b);
        free(gea.x);
        free(L);
        free(U);
        free(gea.x);
        free(Y);
      }else{
        printf("Give a Square Matrix");
      }
      }else if(gcd==3){
        struct abx gea;

        int s1,s2;
          printf("Give the Number of Rows:");
          scanf("%d",&s1);
          printf("Give the Number of Coloumns:");
          scanf("%d",&s2);
          if(s1==s2){
            struct abx gea;
            gea.a=gen(s1,s2);
            printf("Give the B Matrix");
            gea.b=genv(s1);
            gea.x=genrv(s1);
            float** L=genrn(s1,s2);
            float** U=genrn(s1,s2);
            float* Y=genrv(s1);
            int c=0;
            int n=s1;
            int i,j;
            for(i=0;i<n;i++) {
                for(j=0;j<n;j++){
                    if(gea.a[j][i]!=gea.a[i][j])
                        c=c+1;
                }
            }
            if(c==0){
            cholesky(s1,s2,gea.a,L,U,Y,gea.b,gea.x);
            int i,j;
            for(int i=0;i<s1;i++){
              for(int j=0;j<s2;j++){
                printf("%f\t",L[i][j]);
              }printf("\n");
            }printf("\n\n\n");
            for(int i=0;i<s1;i++){
              for(int j=0;j<s2;j++){
                printf("%f\t",U[i][j]);
              }printf("\n");
            }printf("\n\n\n");

          for(i=0;i<s1;i++){
            printf("The root is:%f\n",gea.x[i]);
          }
          free(gea.a);
          free(gea.b);
          free(gea.x);
          free(L);
          free(U);
          free(gea.x);
          free(Y);
        }else{
          printf("Give a Symmetric Matrix\n");
        }
}else{
  printf("Give a Square Matrix\n");
}
      }else{
          printf("Give a Valid Input\n");
  }}
  //If User Chooses Iterative Methods
  else if(dmim==2){
      printf("Enter 1 for Jacobi Method\n");
      printf("Enter 2 for Gauss Seidel Method\n");
      int jg;
      scanf("%d",&jg);
      //Jacobi Method
      if(jg==1){
        int s1,s2,i,j;
          printf("Give the Number of Rows:");
          scanf("%d",&s1);
          printf("Give the Number of Coloumns:");
          scanf("%d",&s2);
          if(s1==s2){
            struct abx gea;
            gea.a=gen(s1,s2);
            gea.b=genv(s1);
            gea.x=genrv(s1);
            float** inversed=genrn(s1,s2);
            float** id=genrn(s1,s2);
            float** D=genrn(s1,s2);
            float** conv=genrn(s1,s2);
            for(i=0;i<s1;i++){
              for(j=0;j<s1;j++){
                if(i==j){
                  id[i][j]=1;
                  D[i][j]=gea.a[i][j];
                }else{
                  id[i][j]=0;
                  D[i][j]=0;
                }
              }
            }
            for(i=0;i<s1;i++){
              for(j=0;j<s1;j++){
                if(i==j){
                  inversed[i][j]=1/D[i][j];
                }else{
                  inversed[i][j]=0;
                }
              }
            }
            multim(s1,s2,s1,s2,inversed,gea.a,conv);

            for(i=0;i<s1;i++){
              for(j=0;j<s1;j++){
                if(i==j){
                conv[i][j]=1-conv[i][j];
                }
              }
            }

            float convc=infmatnom(s1,s2,conv);
            if(convc<1){
                   jacobi(s1,gea.a,gea.b,gea.x);
                   printf("\nThe result is :\n") ;
                   printf("\nThe result is :\n") ;
                   for(i=0;i<s1;i++){
                   printf("\nx[%d] = %f", i + 1,gea.x[i]);
                 }
                 }else{
                   printf("The given equation does not converge for any initial vector\n");
                 }


          free(gea.a);
          free(gea.b);
          free(gea.x);
          free(D);
          free(conv);
          free(id);
          free(inversed);
      }else{
        printf("Give a Square Matrix\n");
      }}
      //Gauss Seidel process
      else if(jg==2){
        struct abx gea;
        int s1,s2,i,j;
        printf("Give the Number of Rows:");
        scanf("%d",&s1);
        printf("Give the Number of Coloumns:");
        scanf("%d",&s2);

        if(s1==s2){
          gea.a=gen(s1,s2);
          gea.b=genv(s1);
          gea.x=genrv(s1);

          float** inversed=genrn(s1,s2);
          float** id=genrn(s1,s2);
          float** D=genrn(s1,s2);
          float** L=genrn(s1,s2);
          float** conv=genrn(s1,s2);
          for(i=0;i<s1;i++){
            for(j=0;j<s1;j++){
              if(i==j){
                id[i][j]=1;
                D[i][j]=gea.a[i][j];
              }
              else if(i>j){
                L[i][j]=gea.a[i][j];
              }
              else{
                id[i][j]=0;
                D[i][j]=0;
                L[i][j]=0;
              }
            }
          }
          for(i=0;i<s1;i++){
            for(j=0;j<s1;j++){
              conv[i][j]=L[i][j]+D[i][j];
            }
          }
          inverse(s1,s2,conv,inversed);
          multim(s1,s2,s1,s2,inversed,gea.a,conv);
          for(i=0;i<s1;i++){
            for(j=0;j<s1;j++){
              conv[i][j]=id[i][j]-conv[i][j];
            }
          }
          float convc=infmatnom(s1,s2,conv);
          if(convc<1){
          gausssiedel(s1,gea.a,gea.b,gea.x);
          printf("\nThe result is :\n") ;
          for(i=0;i<s1;i++){
          printf("\nx[%d] = %f", i + 1, gea.x[i]) ;
        }
        free(gea.a);
        free(gea.b);
        free(gea.x);
        free(D);
        free(id);
        free(L);
        free(inversed);
}else{
  printf("The given equation does not converge for any initial vector\n");
}
  }
  else{
    printf("Give a Square Matrix\n");
  }
      }else{
        printf("Give a Valid Input\n");
      }
    }
    else{
      printf("Give a Valid Input\n");
    }

}else if(pk==2){
  printf("Enter 1 for Matrix Norm Calculation\n");
  printf("Enter 2 for Vector Norm Calculation\n");
  int nv;
  scanf("%d",&nv);
  if(nv==1){
    printf("Enter 1 for Infinite Norm of the Matrix\n");
    printf("Enter 2 for 1-Norm of the Matrix\n");
    printf("Enter 3 for 2-Norm of the Matrix\n");
    int mnn;
    scanf("%d",&mnn);
    if(mnn==1){
      int s1,s2,i;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      printf("Give the Number of Coloumns:");
      scanf("%d",&s2);
      struct matrix mat;
      mat.a=gen(s1,s2);
      float infnom;
      infnom=infmatnom(s1,s2,mat.a);
      printf("The Infinite Norm of the given matrix is:%f\n",infnom);
    }else if(mnn==2){
      int s1,s2,i;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      printf("Give the Number of Coloumns:");
      scanf("%d",&s2);
      struct matrix mat;
      mat.a=gen(s1,s2);
      float nom1;
      nom1=matnom1(s1,s2,mat.a);
      printf("fsdgsag\n");
      printf("The 1-Norm of the given matrix is:%f\n",nom1);
    }
    //Two Norm of the matrix
    else if(mnn==3){

      int s1,s2,i;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      printf("Give the Number of Coloumns:");
      scanf("%d",&s2);
      struct matrix mat;
      mat.a=gen(s1,s2);
      float nomm2;
      nomm2=nom2(s1,s2,mat.a);
      printf("The 2-Norm of the given matrix is:%f\n",nomm2);
    }
  }else if(nv==2){
    printf("Enter 1 for Infinite Norm of the Vector\n");
    printf("Enter 2 for 1-Norm of the Vector\n");
    printf("Enter 3 for 1-Norm of the Vector\n");
    int vnn;
    scanf("%d",&vnn);
    if(vnn==1){
      int s1;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      struct vector vec;
      vec.v=genv(s1);
      float veci;
      veci=infnomv(s1,vec.v);
      printf("The Infinite Norm of the given Vector is:%f\n",veci);

    }else if(vnn==2){
      int s1;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      struct vector vec;
      vec.v=genv(s1);
      float vecn1;
      vecn1=nom1(s1,vec.v);
      printf("The 1-Norm of the given Vector is:%f\n",vecn1);
    }else if(vnn=3){
      int s1;
      printf("Give the Number of Rows:");
      scanf("%d",&s1);
      struct vector vec;
      vec.v=genv(s1);
      float vecn2;
      vecn2=nomv2(s1,vec.v);
      printf("The 2-Norm of the given Vector is:%f\n",vecn2);

    }else{
      printf("Give a Valid Input");
    }
  }else{
    printf("Give a valid input\n");
  }
  }else{
    printf("Give a valid input\n");
  }
}
