/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Homework #01
 *
 *        Version:  1.0
 *        Created:  2022-07-23
 *       Revision:  none
 *       Compiler:  g++
 *
 * 	 Student Name: Song.Yelin
 * 	 Student ID: 2171023
 *   Organization:  Ewha Womans University
 *
 * =====================================================================================
 */

 /*
 * ********** Please read the instructions below carefully ********** 
 * Your name and student ID must be printed when this project is executed
 * Do not print anything other than your name and student ID (Delete printf functions used for debugging when submitting this homework)
 * - If not, there will be 20% penalty
 * Run make clean command before submitting your homework
 * Change this project folder name to studentID_yourname (EX: 1234567_myungkukyoon)
 * You must compress this project folder (not the files in this folder)
 * - If not, there will be 20% penalty
 * - Use ZIP compression utility (DO NOT USE TAR COMMAND)
 * The name of ZIP file must be studentID_yourname.zip (EX: 1234567_myungkukyoon.zip)
 * All the tests must be done in 5 seconds
 * - If not, you will get 0%
 */

#include <stdio.h>

//CA: DO NOT CHANGE
const int MAX = 100;
const char *outputFileName="hw01_output.txt";

//CA: DO NOT CHANGE
int matrixOutput[MAX][MAX] = {0};

//CA: DO NOT CHANGE
void print_output_to_file(FILE *fp1, int ROW, int COL){
	for(int y = 0; y < ROW; y++){
		for(int x = 0; x < COL; x++){
			fprintf(fp1, "%d ", matrixOutput[y][x]);
		}
		fprintf(fp1, "\n");
	}
}

//CA: Please write your code

int main(){
	//CA: YOUR NAME with Student ID
	printf("Song, Yelin (2171023)\n");
	int n; //Total of Test
	int size[3]; //Matrix A and B Sizes
	int A[MAX][MAX];
	int B[MAX][MAX];
	int ROW,COL,MID;
	FILE *fp1 = fopen(outputFileName, "w");
	FILE *fp2=fopen("input.txt","r");
	fscanf(fp2,"%d",&n);
	for(int i=0; i<n; i++){
		for(int i=0; i<3; i++){
			fscanf(fp2,"%d ",&size[i]);
		}
		for(int i=0; i<size[0]; i++){
			for(int j=0; j<size[1]; j++)
				fscanf(fp2,"%d ",&A[i][j]);
		}
		for(int i=0; i<size[1]; i++){
			for(int j=0; j<size[2]; j++)
				fscanf(fp2,"%d ",&B[i][j]);
		}
		ROW=size[0];
		COL=size[2];
		MID=size[1];
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COL; j++){
				for(int k=0; k<MID; k++){
					matrixOutput[i][j]+=A[i][k]*B[k][j];
				}
			}
		}
		print_output_to_file(fp1, ROW, COL);
		for(int i=0; i<ROW; i++){
			for(int j=0; j<COL; j++){
				matrixOutput[i][j]=0;}
		}
	}
		fclose(fp2);
	fclose(fp1);
	
	return 0;
}


