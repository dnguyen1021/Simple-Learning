#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char **argv)
{
	char input[999], input2[999];
	char *split;
	FILE *file1;
	FILE *file2;
	file1 = fopen(argv[1], "r");
	file2 = fopen(argv[2], "r");
	fgets(input, 999, file1);
	int K = atoi(input);
	fgets(input, 999, file1);
	int N = atoi(input);
	fgets(input2, 999, file2);
	int H = atoi(input2);
	long double X[N][K+1];
	long double temp[N][K+1];
	long double Y[N];
	long double tranpose[K+1][N];
	long double xtranposex[K+1][K+1];
	int tp = K + 1;
	long double tmp;
	long double temp2[H][K];
	long double augmatrix[K+1][tp*2];
	long double tempo, r;
	int tem;
	long double inverse[K+1][K+1];
	long double inversetranpose[K+1][N];
	long double W[K+1];
	long double test[H][K+1];
	long double house[H];
	
	/*float **res;
	
	res=(float**)calloc(N,sizeof(float*));*/

	//Copy input to tmp array.
	for (int i = 0; i < N; i++)
	{
		fgets(input, 999, file1);
		split = strtok(input, ",");
		int j = 0;
		while (split != NULL)
		{
			long double val = atof(split);
			temp[i][j] = val;
			j++;
			split = strtok(NULL, ",");
		}
	}
	
	//Copy input to temp2 array
	for (int i = 0; i < H; i++)
	{
		fgets(input2, 999, file2);
		split = strtok(input2, ",");
		int j = 0;
		while (split != NULL)
		{
			long double val = atof(split);
			temp2[i][j] = val;
			j++;
			split = strtok(NULL, ",");
		}
	}
	//copy temp array to test
	for (int i = 0; i < H; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int plc2 = 0;
			test[i][j+1] = temp2[i][j];
			test[i][plc2] = 1;
		}
	}
	//print test array
	/*for (int i = 0; i < H; i++)
	{
		printf("\n");
		for (int j = 0; j < K+1; j++)
			printf("%Lf\t", test[i][j]);
	}
	printf("\n");*/

	
	//Copy tmp to X
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K; j++)
		{
			int plc = 0;
			X[i][j+1] = temp[i][j];
			X[i][plc] = 1;
		}
	}

	//Copy tmp to Y
	int count = K;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < K+1; j++)
		{
			if(j == count)
			{
				Y[i] = temp[i][j];
			}
		}
	}	
	/*for (int i = 0; i < N; i++)
	{
		fgets(input, 999, file1);
		split = strtok(input, ",");
		while (split != NULL)
		{
		for (int atr = 0; atr < K+1; atr++)
		{	
			if(atr < K)
			{
				int plc = 0;
				float val = atoi(split);
				X[i][atr+1] = val;
				X[i][plc] = 1;	
				split = strtok(NULL, ",");
			}
			if (atr == K)
			{

				float val = atoi(split);
				Y[i] = val;                {

				split = strtok(NULL, ",");
			}
			
		}
	}*/
	/*float **xtranposex;
	int k1 = K + 1;
	xtranposex = malloc(sizeof(float*)*k1);
	for (int i = 0; i < k1; i++)
	{
		xtranposex[i] = malloc(sizeof(float)*k1);
	}*/
	
	/*for (int i = 0; i < k1; i++)
	{
		for (int j = 0; j < k1; j++)
		{
			xtranposex[i][j] = 0;
		}
	}*/

	//print X
	/*for (int i = 0; i < N; i++)
	{
		printf("\n");
		for (int j = 0; j < K+1; j++)
			printf("%Lf\t", X[i][j]);
	}
	printf("\n");*/
	
	//print tranpose X
	for(int i = 0; i < N; i++)
		for(int j = 0; j < K+1; j++)
			tranpose[j][i] = X[i][j];

	/*for(int i = 0; i < K+1; i++)
	{
		printf("\n");
		for (int j = 0; j < N; j++)
			printf("%Lf\t", tranpose[i][j]);
	}
	printf("\n");
	printf("\n");*/
	
	//print Y
	/*for(int i = 0; i < N; i++)
	{
		printf("%Lf\t", Y[i]);
	}
	printf("\n");
	printf("\n");*/

		
	for (int i = 0; i < tp; i++)
	{	
		for (int j = 0; j < tp; j++)
		{
			tmp = 0;
			for (int l = 0; l < N; l++)
			{
				tmp += tranpose[i][l]*X[l][j];
			}
			xtranposex[i][j] = tmp;
		}
	}
		
	//print xtranposex
	/*for(int i = 0; i < tp; i++)
	{
		printf("\n");
		for (int j = 0; j < tp; j++)
			printf("%Lf\t", xtranposex[i][j]);
	}
	printf("\n");*/

	/*float a = 0;
	a = tranpose[0][0]*X[0][0];
	printf("%f\n", a);
	a = a + tranpose[0][1]*X[1][0];
	printf("%f\n", a);
	a = a + tranpose[0][2]*X[2][0];
	printf("%f\n", a);
	float b = 0;
	b += tranpose[0][0]*X[0][1];
	b += tranpose[0][1]*X[1][1];
	b += tranpose[0][2]*X[2][1];
	printf("%f\b", b);*/

	//Copy xtranposex to augmatrix
	for (int i = 0; i < K+1; i ++)
	{
		for (int j = 0; j < K + 1; j++)
		{
			augmatrix[i][j] = xtranposex[i][j];
		}
	}
	//Add identity matrix to aug matrix
	for (int i = 0; i < K+1; i++)
	{
		for (int j = K+1; j < 2*tp; j++)
		{
			if (i==j%tp)
			{
				augmatrix[i][j]=1;
			}
			else
			{
				augmatrix[i][j]=0;
			}	
		}	
	}
	//print augmatrix
	/*for (int i = 0; i < K+1; i++)
	{
		printf("\n");
		for (int j = 0; j < tp*2; j++)
		{
			printf("%Lf\t", augmatrix[i][j]);
		}
	}*/
	
	//Gausssian Elimination
	for (int j = 0; j < K+1; j++)
	{
		tem = j;
		for(int i = j+1; i < K+1; i++)
		{
			if (augmatrix[i][j]>augmatrix[tem][j])
			{
				tem = i;
			}
		}
		if(tem!=j)
		{
			for (int k = 0; k <2*tp; k++)
			{
				tempo=augmatrix[j][k];
				augmatrix[j][k]=augmatrix[tem][k];
				augmatrix[tem][k]=tempo;
			}
		}
		for (int i = 0; i < K+1; i++)
		{
			if (i!=j)
			{
				r = augmatrix[i][j];
				for(int k=0; k < 2*tp; k++)
				{
					augmatrix[i][k] -= (augmatrix[j][k]/augmatrix[j][j])*r;
				}
			}
			else
			{
				r = augmatrix[i][j];
				for(int k = 0; k < 2*tp; k++)
				{
					augmatrix[i][k] /= r;
				}
			}
		}
			
	}
	
	//print aug matrix after gasssian
	/*printf("\n");
	for (int i = 0; i < K+1; i++)
	{
		printf("\n");
		for (int j = 0; j < 2*tp; j++)
		{
			printf("%Lf\t", augmatrix[i][j]);
		}
	}*/
	
	//copy augmatrix to inversetranpose
	for (int i = 0; i < K+1; i++)
	{
		for (int j = 0; j < K + 1; j++)
		{
			inverse[i][j] = augmatrix[i][(K+1)+j];
		}
	}
	//print inverse
	/*printf("\n");
	for(int i = 0; i < K+1; i++)
	{
		printf("\n");
		for (int j = 0; j < K+1; j++)
		{
			printf("%Lf\t", inverse[i][j]);
		}
	}*/
	
	//inversetranpose
	/*for (int i = 0; i < tp; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp = 0;
			for (int l = 0; l < N; l++)
			{
				tmp += inverse[i][l]*tranpose[l][j];
			}
			inversetranpose[i][j] = tmp;
		}
	}*/

	for (int i = 0; i < K+1; i++)
	{
		for (int j = 0; j < N; j++)
		{
			tmp = 0;
			for (int l = 0; l < K+1; l++)
			{
				tmp += inverse[i][l]*tranpose[l][j];
			}
			inversetranpose[i][j] = tmp;
		}
	}

	//print inversetranpose
	/*printf("\n");
	for(int i = 0; i < K+1; i++)
	{
		printf("\n");
		for (int j = 0; j < N; j++)
		{
			printf("%Lf\t", inversetranpose[i][j]);
		}
	}*/

	//find W
	for (int i = 0; i < K+1; i++)
	{
		tmp = 0;
		for (int j  = 0; j < N; j++)
		{
				tmp += inversetranpose[i][j]*Y[j];
		}
		W[i] = tmp;
		
	}
	/*printf("\n");
	for(int i = 0; i < K+1; i++)
	{
		printf("%Lf\n", W[i]);
	}*/
	
	//test * weight
	for (int i = 0; i < H; i++)
	{
		tmp = 0;
		for (int j = 0; j < K + 1; j++)
		{
			tmp += test[i][j]*W[j];
		}
		house[i] = tmp;
	
			
	}
	for(int i = 0; i < H; i++)
	{
		printf("%0.0Lf\n", house[i]);
	}
	

}
	

