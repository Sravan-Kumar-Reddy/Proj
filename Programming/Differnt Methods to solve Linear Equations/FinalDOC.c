#include<stdio.h>
#include<stdlib.h>
#include<math.h>
//Zero Matrix generation
float** genrn(int row, int column){
  float** ptr;
  int i;
  int j;
  int k;
  ptr = (float **)calloc(row,row*sizeof(float*));
  for (k=0; k<column; k++){
    ptr[k]=(float *)calloc(column,sizeof(float));
  }
  for(i = 0; i<row;i++){
    for (j = 0;j < column; j++){
      ptr[i][j]=0;
    }
  }
  return ptr;
}
//User Defined Vector
float* genv(int num){
  float* ptr;
  int i;
  int j;
  int k;
  ptr = (float *)calloc(num,num*sizeof(float*));
  for(i = 0; i<num;i++){
      printf("Give the %dth element:",i+1);
      scanf("%f",&ptr[i]);
  }
  return ptr;
}
//Zero Vector Generation
float* genrv(int num){
  float* ptr;
  int i;
  int j;
  int k;
  ptr = (float *)calloc(num,num*sizeof(float*));
  for(i = 0; i<num;i++){
      ptr[i]=0;
  }
  return ptr;
}
//Matrix Generator
float** gen(int row, int column){
  float** ptr;
  int i;
  int j;
  int k;
  ptr = (float **)calloc(row,row*sizeof(float*));
  for (k=0; k<column; k++){
    ptr[k]=(float *)calloc(column,sizeof(float*));
  }
  for(i = 0; i<row;i++){
    for (j=0;j<column; j++){
      printf("Give the value in a[%d][%d]:",i,j);
      scanf("%f",&ptr[i][j]);
    }
  }
  return ptr;
}
//Determinrnt of the Matrix
float det(int s1,int s2,float** l){
  float detm,p;
  int sign=1;
  if(s1==s2){
    if (s1==2){
      detm=(l[0][0]*l[1][1])-(l[0][1]*l[1][0]);
      return detm;
    }
    else{
        float k[s1];
        int ih;
        for(ih=0;ih<s1;ih++){
          k[ih]=l[0][ih];
        }
      float detm=0;
      int i1,i,j,ik,jk;
      float** mm=genrn(s1-1,s2-1);
      for(i1=0;i1<s1;i1++){
        float k1,k2;
        k1=0;
        k2=0;
        int count=0;
        int count1=0;
        for(i=0;i<s2;i++){
          for(j=0;j<s1;j++) {
            if(i!=0 && j!=i1){
              mm[count][count1]=l[i][j];
              count1=count1+1;
              if(count1>=s2-1){
                count1=0;
                count+=1;
                }
              }
  }
  }

            p=det(s1-1,s2-1,mm);
            if(i1%2==0){
              detm=detm+k[i1]*p;
              }
              else{
                detm+=-1*k[i1]*p;
              }
            }
          }
        }
          else{return -1;}
        }
//transpose of a matrix
void transm(int s1,int s2,float** A,float** B){
        int i,j;
        for(i=0;i<s1;i++){
          for(j=0;j<s2;j++){
              B[j][i]=A[i][j];
            }
          }
          return;
        }
//Inverse of a matrix
void inverse(int s1,int s2,float** l,float** inv){
  if(s1==s2){
    float k[s1+s2];
    float** cofac=genrn(s1,s2);

    int i1,j1,i,j,ik,jk;
    float** mm=genrn(s1-1,s2-1);
    for(i1=0;i1<s1;i1++){
      for(j1=0;j1<s1;j1++){

        float k1,k2;
        k1=0;
        k2=0;
        int count=0;
        int count1=0;
        for(i=0;i<s2;i++){
          for(j=0;j<s1;j++) {
            if(i!=i1 && j!=j1){

              mm[count][count1]=l[i][j];
              count1=count1+1;
              if(count1>=s2-1){
                count1=0;
                count+=1;
              }
}
}
}



float p=det(s1-1,s2-1,mm);
float ss=det(s1,s2,l);
  cofac[i1][j1]=pow(-1,i1+j1)*(p/ss);
  }
  }
transm(s1,s1,cofac,inv);



  }else{
    printf("Give A square matrix");
  }
}
//function for infinite norm of a vector
float infnomv(int n,float* vec){
  int i,j;float temp;
  float infnom=0;
  for(i=0;i<n;i++){
    if (infnom<vec[i]){
      infnom=vec[i];
    }
  }
return infnom;
}
//Function for 2norm of a vector
float nomv2(int n,float* vec){
  int i;
  float sum;
  for(i=0;i<n;i++){
    sum=sum+pow(vec[i],2);
  }
  float nomv=pow(sum,0.5);
  return nomv;
}
//Function for 1 norm of a vector
float nom1(int n,float* vec){
  int i,j;float temp;
  float nom1=0;
  for(i=0;i<n;i++){
    nom1=nom1+vec[i];
  }
return nom1;
}
//Multiplication of the Matrix
void multim(int s1,int s2,int s3,int s4,float** a,float** b,float** su){
if(s2==s3){
  int i,j,k;
  float sum;
  for(i=0;i<=s1-1;i++){
    for(j=0;j<=s4-1;j++){
      sum=0;
      for(k=0;k<=s2-1;k++){
      sum=sum+a[i][k]*b[k][j];
      }
      su[i][j]=sum;
    }
  }
}else{
  printf("Multiplication is not possible");
}
}

//Function for 1norm of a matrix
float matnom1(int r,int c,float **vec){
  int i,j;
  float colsum=0;
  float matnom1=0;
  for(j=0;j<c;j++){
    colsum=0;
    for (i=0;i<r;i++){
      colsum=fabs(vec[i][j])+colsum;
    }
    if(colsum>matnom1){
      matnom1=colsum;
    }
  }
return (matnom1);
}
//Function for infinite of a matrix
float infmatnom(int r,int c,float** vec){
  int i,j;
  float rowsum=0;
  float infmatnom=0;
  for(i=0;i<r;i++){
    rowsum=0;
    for (j=0;j<c;j++){
      rowsum=fabs(vec[i][j])+rowsum;
    }
    if(rowsum>infmatnom){
      infmatnom=rowsum;
    }
  }
return (infmatnom);
}


//Spectral Radius of a Matrix
float spr(int s1,int s2,float** ar,float** arr){
  float rk,rn,a,b;
  float** xn=genrn(s2,2);
  float** xnp=genrn(s2,2);
  int i,j;
  for(i=0;i<s2;i++){
    j=0;
    xn[i][j]=arr[i][j];
  }
  rn=0;
  rk=1;
  while(1<2){
    if(abs(rk-rn)>0.00000000000000000000001){
      rn=rk;
      multim(s1,s2,s2,1,ar,xn,xnp);
      a=infmatnom(2,1,xn);
      b=infmatnom(2,1,xnp);
      rk=b/a;
      for(i=0;i<s2;i++){
        j=0;
        xn[i][j]=xnp[i][j];
      }
    }else{
      break;
    }
  }
  return rk;
}

//Two norm of a matrix
float nom2(int s1,int s2,float** arr){

  float** apkt=genrn(s1,s2);

  float** ask=genrn(s1,2);
  float** aatm=genrn(s1,2);

  transm(s1,s1,arr,apkt);
  multim(s1,s2,s1,s2,apkt,arr,aatm);
  float k=spr(s1,s2,aatm,ask);
  float nom2=pow(k,0.5);
  return nom2;
}
//Doolittle Decomposition of the Matrix
void dolildecomp(int s1,int s2,float** A,float** L,float** U,float* Y,float* B,float* X){
  int i,j,k,n;
  n=s1;
  for(j=0; j<n; j++)
  {
      for(i=0; i<n; i++)
      {
          if(i<=j)
          {
              U[i][j]=A[i][j];
              for(k=0; k<=i-1; k++)
                  U[i][j]-=L[i][k]*U[k][j];
              if(i==j)
                  L[i][j]=1;
              else
                  L[i][j]=0;
          }
          else
          {
              L[i][j]=A[i][j];
              for(k=0; k<=j-1; k++)
                  L[i][j]-=L[i][k]*U[k][j];
              L[i][j]/=U[j][j];
              U[i][j]=0;
          }
      }
  }
  for(i=0; i<n; i++)
  {
      Y[i]=B[i];
      for(j=0; j<i; j++)
      {
          Y[i]-=L[i][j]*Y[j];
      }
  }
  for(i=n-1; i>=0; i--)
  {
      X[i]= Y[i];
      for(j=i+1; j<n; j++)
      {
          X[i]-=U[i][j]*X[j];
      }
      X[i]/=U[i][i];
  }
}
//Gaussian ELimination
void GaussElimination(int s1,float** a,float* x){
  int k,i,j,n;
  float s,p;
  n=s1;
  for(k = 0 ; k < n - 1 ; k++){
  for(i = k + 1 ; i < n ; i++){
   p = a[i][k] / a[k][k] ;
   for(j = k ; j < n + 1 ; j++)
    a[i][j] = a[i][j] - p * a[k][j] ;
  }
 }
 x[n-1] = a[n-1][n] / a[n-1][n-1] ;
 for(i = n - 2 ; i >= 0 ; i--){
  s=0;
  for(j = i + 1 ; j < n ; j++){
   s += (a[i][j]* x[j]) ;
   x[i] = (a[i][n]-s)/a[i][i] ;
  }
 }

}
//Cholesky Decomposition and Solving
void cholesky(int row,int colou,float** A,float** L,float** U,float* Y,float* B,float* X){
  int i,j,k,n;
  n=row;
  float s1,s2;
  n=s1;
  for (i=0;i<n;i++){
      for (j=0;j<n;j++){
          s1=0;s2=0;
	      if (i>j){
	    if(j>0){
		for(k=1;k<(j+1);k++){
                s2=s2+L[i][k-1]*L[j][k-1];
              }
              }
	      L[i][j]=(A[i][j]-s2)/L[j][j];
          }
       else if (i==j){
             for(k=0;k<i;k++){
                     s1=s1+L[i][k]*L[i][k];
                }
                L[i][j]=sqrt((A[i][j])-s1);
            }
       else {
            L[i][j]=0;
        }

    }
    }
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            U[i][j]=L[j][i];
        }
    }
    for(i=0; i<n; i++)
    {
        Y[i]=B[i];
        for(j=0; j<i; j++)
        {
            Y[i]-=L[i][j]*Y[j];
        }
    }
    for(i=n-1; i>=0; i--)
    {
        X[i]= Y[i];
        for(j=i+1; j<n; j++)
        {
            X[i]-=U[i][j]*X[j];
        }
        X[i]/=U[i][i];
    }
}

//GaussSiedel Method
void gausssiedel(int s1,float** a,float* b,float* x){
  int i, j, k, n ,m ;
  float p,s,c;
  n=s1;
     float k1=infnomv(s1,x);
      for(i=0;i<n;i++) {
          c=b[i];
          for(j=0;j<n;j++) {
              if(i!=j) {
                  c=c-a[i][j]*x[j];
              }
          }
          x[i]=c/a[i][i];
      }

  float k2=infnomv(s1,x);


  while(1<2){
    if((fabs(k1-k2))>pow(10,-16)){

  k1=infnomv(s1,x);
    for(i=0;i<n;i++) {
        c=b[i];
        for(j=0;j<n;j++) {
            if(i!=j) {
                c=c-a[i][j]*x[j];
            }
        }
        x[i]=c/a[i][i];
    }
    k2=infnomv(s1,x);
  }else{
    break;
  }

}
}

//Jacobi Method
void jacobi(int s1,float** a,float* b,float* x){
  int i,j,m,n,l;
  float* cpk=genrv(s1);
  n=s1;
  float k1=infnomv(s1,x);
   for(i=0;i<n;i++) {
       cpk[i]=b[i];
       for(j=0;j<n;j++) {
           if(i!=j) {
               cpk[i]=cpk[i]-a[i][j]*x[j];
           }
       }
       x[i]=cpk[i]/a[i][i];
   }

float k2=infnomv(s1,x);


while(1<2){

 if((fabs(k1-k2))>pow(10,-16)){
   float* cpk=genrv(s1);
   for(i=0;i<s1;i++){
     cpk[i]=x[i];
}
k1=infnomv(s1,cpk);
 for(i=0;i<n;i++){
     cpk[i]=b[i];
     for(j=0;j<n;j++) {
         if(i!=j) {
             cpk[i]=cpk[i]-a[i][j]*x[j];
         }
     }
     x[i]=cpk[i]/a[i][i];
 }
 k2=infnomv(s1,x);
}else{
 break;
}

}

}
