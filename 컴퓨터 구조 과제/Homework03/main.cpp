/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Homework #03
 *
 *        Version:  1.0
 *        Created:  2022-09-15
 *       Revision:  none
 *       Compiler:  g++
 *
 * 	 Student Name: Song yelin
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

 /*
 * Input instructions
 * add, sub, addi, sw, lw
 */

#include <stdio.h>
#include <math.h>
//CA: DO NOT CHANGE
const char *inputInstFile="input_inst.txt";
const char *inputRegFile="input_reg.txt";
const char *inputMemFile="input_mem.txt";
const char *outputFileName="hw03_output.txt";

const unsigned MAX_REG_SIZE = 32;
const unsigned MAX_MEM_SIZE = 1024;

unsigned Register[MAX_REG_SIZE] = {0};
unsigned Memory[MAX_MEM_SIZE] = {0};

void print_output_to_file(FILE *fp){
	for(unsigned i = 0; i < MAX_REG_SIZE; i++){
		fprintf(fp, "%08x\n", Register[i]);
	}
	for(unsigned i = 0; i < MAX_MEM_SIZE; i++){
		fprintf(fp, "%08x\n", Memory[i]);
	}
}
void write_array(){
	int k,j;
	FILE *fpmem =fopen(inputMemFile,"r");
	FILE *fpreg=fopen(inputRegFile,"r");
	for(unsigned i=0; i<MAX_MEM_SIZE; i++){
		fscanf(fpmem,"%x",&j);
		Memory[i]=j;
		fgetc(fpmem);
	}
	for(unsigned i=0; i<MAX_REG_SIZE; i++){
		fscanf(fpreg,"%x",&k);
		Register[i]=k;
		fgetc(fpreg);
		}
	fclose(fpmem);
	fclose(fpreg);
}
void R_formet(unsigned int b[]){
	int i;
	int x=0,rs2=0,rs1=0,rd=0;
		for(i=0; i<7; i++)
			x+=b[7-1-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
			
		}
		rs1=Register[rs1];
		rs2=Register[rs2];
		if(x==0)
			Register[rd]=rs1+rs2;
		else
			Register[rd]=rs1-rs2;
}
void I_format(unsigned int b[]){
	int i;
	int rd=0,add=0,rs1=0;
	int imd=0;
	int t=0;
		for(int j=0; j<7; j++){
		t+=b[31-j]*pow(2,j);
	}
		if(b[0]==1){
			imd=-1*pow(2,11);
			for(i=0; i<11; i++)
				imd+=b[12-2-i]*pow(2,i);
		}
		else
			for(i=0; i<12; i++)
				imd+=b[11-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
		}
		rs1=Register[rs1];
	if(t==19){
		Register[rd]=rs1+imd;}
	else{
		rs1=Register[rs1];
		add=(rs1+imd)/4;
		imd=Memory[add];
		Register[rd]=imd;
		}
}
void S_format(unsigned int b[]){
	int imd=0;
	int i;
	int rs2=0,rs1=0,rs=0;
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
		}
		for(i=0; i<5; i++)
			imd+=b[31-7-i]*pow(2,i);
		for(i=0; i<7; i++)
				imd+=b[7-1-i]*pow(2,i+5);
	rs1=Register[rs1];
	rs=(rs1+imd)/4;
	rs2=Register[rs2];
	Memory[rs]=rs2;
		

}


int main(){
	//CA: YOUR NAME with Student ID
		printf("Song, Ye lin (2171023)\n");
	int n;
	long long a;
	int h[8]={0},b[32]={0};
	int imd,rs2, rs1,rd,add;
	FILE *fp1 = fopen(outputFileName, "w");
	FILE *fp2=fopen(inputInstFile,"r");
	write_array();
	Register[0]=0;
	fscanf(fp2,"%d",&n);
	fgetc(fp2);

	for(int y=0; y<n; y++){
		h[8]={0},b[32]={0};
		fscanf(fp2,"%llx",&a);
		fgetc(fp2);
		for(int i=31; i>=0; i--){
			b[i]=a%2;
			a/=2;
		}


	int t=0;
	for(int i=0; i<7; i++){
		t+=b[31-i]*pow(2,i);
	}
	if(t==51)
	{
	int i;
	int x=0;
	rs2=0,rs1=0,rd=0;
		for(i=0; i<7; i++)
			x+=b[7-1-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
			
		}
		rs1=Register[rs1];
		rs2=Register[rs2];
		if(x==0)
			Register[rd]=rs1+rs2;
		else
			Register[rd]=rs1-rs2;
	}
	else if(t==19||t==3)
{
		imd=0,rs1=0,rd=0;
		int result=0;
		int i;
		if(b[0]==1){
			imd=-1*pow(2,11);
			for(i=0; i<11; i++)
				imd+=b[11-i]*pow(2,i);
		}
		else
			for(i=0; i<12; i++)
				imd+=b[12-1-i]*pow(2,i);
		for(i=0; i<5; i++){
			rs1+=b[7+5+5-1-i]*pow(2,i);
			rd+=b[7+5+5+3+5-1-i]*pow(2,i);
		}
		rs1=Register[rs1];
	if(t==19){
		Register[rd]=rs1+imd;}
	else{
		add=(rs1+imd)/4;
		result=Memory[add];
		Register[rd]=result;
		}
}
	else if(t==35)
	{
		int i;
		rs2=0,rs1=0,imd=0;
		int rs=0, result=0;
		if(b[0]==1) imd=-1*pow(2,11);
		for(i=0; i<5; i++){
			rs2+=b[7+5-1-i]*pow(2,i);
			rs1+=b[7+5+5-1-i]*pow(2,i);
		}
		
			for(i=0; i<5; i++)
				imd+=b[31-7-i]*pow(2,i);
			for(i=0; i<6; i++)
				imd+=b[7-1-i]*pow(2,i+5);
				rs1=Register[rs1];
	rs=(rs1+imd)/4;
	result=Register[rs2];
	Memory[rs]=result;
	

	}
	Register[0]=0;
}
	print_output_to_file(fp1);
	fclose(fp2);
	fclose(fp1);
	return true;
}
