/*
 * =====================================================================================
 *
 *       Filename:  main.cpp
 *
 *    Description:  Homework #04
 *
 *        Version:  1.0
 *        Created:  2022-09-17
 *       Revision:  none
 *       Compiler:  g++
 *
 * 	 Student Name:
 * 	   Student ID:
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
#include <stdlib.h>
#include <math.h>
//CA: DO NOT CHANGE
const char *outputFileName="hw04_output.txt";

unsigned long long cacheHit;
unsigned long long cacheMiss;

void init(){
    cacheHit = 0;
    cacheMiss = 0;
}

void ratio(FILE *fp){
    unsigned long long total = cacheHit + cacheMiss;
    fprintf(fp, "Hit: %3.2f\n", (float)cacheHit/total * 100);
    fprintf(fp, "Miss: %3.2f\n", (float)cacheMiss/total * 100);
}

//CA: Please write your code
int main(){
    unsigned int cache[512]={0};
    unsigned char y[512]={0};
    unsigned int n,blocks,block_size,a,j,i,c,tag,index,k;
    unsigned int add,b;
	init();
    //CA: YOUR NAME with Student
    printf("Song, Ye lin (2171023)\n");
    FILE *fp = fopen(outputFileName, "w");
    FILE *fp1 = fopen("input.txt", "r");
    fscanf(fp1,"%d",&n);
    fgetc(fp1);
    for(i=0; i<n; i++){
		for(k=0; k<512; k++){
        y[k]=0;
        cache[k]=0;}
		    cacheHit = 0;
    cacheMiss = 0;
        b=0,tag=0,index=0;
        fscanf(fp1,"%d",&blocks);
        fgetc(fp1);
        fscanf(fp1,"%d",&block_size);
        fgetc(fp1);
        fscanf(fp1,"%d",&c);
        fgetc(fp1);
        for(j=0; j<c; j++)
        {
            fscanf(fp1,"%x",&add);
            fgetc(fp1);
            b=add/block_size;
            index=b%blocks;
            if(y[index]==0){
                cacheMiss++;
                cache[index]=b/blocks;
                y[index]=1;
            }
            else if(y[index]==1){
                if(cache[index]==b/blocks)
                    cacheHit++;
                else
                {
                    cacheMiss++;
                    cache[index]=b/blocks;
                }
            }
        }
        ratio(fp);
    }

    fclose(fp1);
    fclose(fp);
    return 1;
}
