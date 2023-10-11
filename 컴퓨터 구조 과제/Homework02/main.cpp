/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Homework #02
 *
 *        Version:  1.0
 *        Created:  2022-09-15
 *       Revision:  none
 *       Compiler:  g++
 *
 * 	 Student Name: SongYelin
 * 	 Student ID:  2171023
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

 /*
 * Input instructions
 * add, sub, addi, sw, lw, beg
 */

#include <stdio.h>
#include <math.h>
//CA: DO NOT CHANGE
const char *outputFileName="hw02_output.txt";

//CA: Please write your code
void hax_to_binary(int *h,int *b){
	int k=0;
	for(int i=0; i<8; i++){
		for(int j=3; j>=0; j--){
			b[k+j]=h[i]%2;
		h[i]/=2;}
		k+=4;
	}

}
void r_type(FILE **fp1,int *b,int t);
void i_type(FILE **fp1,int *b,int t);
void s_sb_type(FILE **fp1,int *b,int t);

		
int main(){

	//CA: YOUR NAME with Student ID
	printf("Song, Ye lin (2171023)\n");
	int n;
	int a,h[8]={0},b[32]={0};
	int imd,rs2, rs1,rd;
	FILE *fp1 = fopen(outputFileName, "w");
	FILE *fp2=fopen("input.txt","r");
	fscanf(fp2,"%d",&n);
	fgetc(fp2);
	for(int y=0; y<n; y++){
		h[8]={0},b[32]={0};
		fscanf(fp2,"%x",&a);
		fgetc(fp2);
		for(int i=7; i>=0; i--){
			h[i]=a%16;
			a/=16;
		}
	hax_to_binary(h,b);
	int t=0,s=0,i;
	for(int i=0; i<7; i++){
		t+=b[31-i]*pow(2,i);
	}
	if(t==51)
	{
		int x=0;
		rs2=0, rs1=0,rd=0;
		for(i=0; i<7; i++)
			x+=b[7-1-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
		}
		if(x==0)
			fprintf(fp1,"add x%d,x%d,x%d",rd,rs1,rs2);
		else
			fprintf(fp1,"sub x%d,x%d,x%d",rd,rs1,rs2);
	}
	else if(t==19||t==3)
{
		imd=0,rs1=0,rd=0;
		if(b[0]==1){
			imd=-1*pow(2,11);
			for(i=0; i<11; i++)
				imd+=b[12-2-i]*pow(2,i);
		}
		else
			for(i=0; i<12; i++)
				imd+=b[12-1-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
		}
		if(t==19)
			fprintf(fp1,"addi x%d,x%d,%d",rd,rs1,imd);
		else
			fprintf(fp1,"lw x%d,%d(x%d)",rd,imd,rs1);
}
	else		
		{
		rs2=0,rs1=0,imd=0;
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
		}
		if(t==35){
			for(i=0; i<5; i++)
				imd+=b[31-7-i]*pow(2,i);
			for(i=0; i<7; i++)
				imd+=b[7-1-i]*pow(2,i+5);
			fprintf(fp1,"sw x%d,%d(x%d)",rs2,imd,rs1);
		}
		else{
			imd+=b[0]*pow(2,11);
			imd+=b[7]*pow(2,10);
			for(i=0; i<4; i++)
				imd+=b[31-7-1-i]*pow(2,i);
			for(i=4; i<10; i++)
				imd+=b[31-25+4-i]*pow(2,i);
			imd*=2;
			fprintf(fp1,"beq x%d,x%d,%d",rs1,rs2,imd);
		}
}
	fprintf(fp1,"\n");
	}
	
	fclose(fp2);
	fclose(fp1);
	
	return true;
}
