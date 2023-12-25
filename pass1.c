/*not my no error



#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
int len=0,start_address=0,flag=0;
FILE *finput,*foptab,*finter,*fsymtab;
finput = fopen("input.txt","r");
foptab = fopen("optab.txt","r");
finter = fopen("inter.txt","w");
fsymtab = fopen("symtab.txt","w");
char label[20],opcode[20],operand[20],optabval[20],optabhexcode[20];
int locctr=0;
fscanf(finput,"%s %s %s",label,opcode,operand);
start_address=atoi(operand);
if(strcmp(opcode,"START")==0) {
locctr=atoi(operand);
fprintf(finter,"\t%s\t%s\t%s\n%d",label,opcode,operand,locctr);
}
else
locctr=0;
fscanf(finput,"%s %s %s",label,opcode,operand);
while(strcmp(opcode,"END")!=0) {
flag=0;
if(strcmp(label,"**")!=0) {
fprintf(fsymtab,"%s\t%d\n",label,locctr);
}
else {
while(!feof(foptab)) {
fscanf(foptab,"%s%s",optabval,optabhexcode);
if(strcmp(opcode,optabval)==0) {
locctr+=3;
flag=1;
break;
}
}
if(flag==0)
{
printf("\nError!! Opcode not found!!\n");
exit(0);
}
}

if(strcmp(opcode,"WORD")==0)
locctr+=3;
else if(strcmp(opcode,"RESW")==0)
locctr+=3*atoi(operand);
else if(strcmp(opcode,"RESB")==0)
locctr+=atoi(operand);
fprintf(finter,"\t%s\t%s\t%s\n%d",label,opcode,operand,locctr);
fscanf(finput,"%s %s %s",label,opcode,operand);
}
fprintf(finter,"\t%s\t%s\t%d",label,opcode,start_address);
printf("Pass1 Successfull\n");
printf("Program length=%d\n",locctr-start_address);
fclose(finput);
fclose(foptab);
fclose(finter);
fclose(fsymtab);
}




*/


//kiran ka code
/*
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
char label[30],opcode[20],operand[20],code[20],mne[20];
int start,locctr,len;

FILE *fin,*fop,*finter,*fsym;
fin=fopen("input.txt","r");
fop=fopen("opcode.txt","r");
finter=fopen("intermediate.txt","w");
fsym=fopen("symtab.txt","w");

fscanf(fin,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0){
start=atoi(operand);
locctr=start;
fprintf(finter,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
fscanf(fin,"%s\t%s\t%s",label,opcode,operand);
}
while(strcmp(opcode,"END")!=0){
fprintf(finter,"%d\n",locctr);

if(strcmp(label,"**")!=0)
fprintf(fsym,"%s\t%d\n",label,locctr);
fscanf(fop,"%s\t%s",code,mne);
while(fscanf(fop, "%s\t%s", code, mne) == 2){
if(strcmp(opcode,code)==0){
locctr=locctr+3;
break;
}

fclose(fop);
fscanf(fop,"%s\t%s",code,mne);
}
if(strcmp(opcode,"WORD")==0)
locctr=locctr+3;
else if(strcmp(opcode,"RESW")==0)
locctr=locctr+(3*atoi(operand));
else if(strcmp(opcode,"RESB")==0)
locctr=locctr+atoi(operand);
else if(strcmp(opcode,"BYTE")==0)
locctr++;

fprintf(finter,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(fin,"%s\t%s\t%s",label,opcode,operand);

}
fprintf(finter,"%d\t%s\t%s\t%s",locctr,label,opcode,operand);

fclose(fin);
fclose(fop);
fclose(finter);
fclose(fsym);
}

*/



#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void main(){
char label[30],opcode[20],operand[20],code[20],mne[20];
int start,locctr,len;

FILE *fin,*fop,*finter,*fsym;
fin=fopen("input.txt","r");
fop=fopen("opcode.txt","r");
finter=fopen("intermediate.txt","w");
fsym=fopen("symtab.txt","w");

fscanf(fin,"%s\t%s\t%s",label,opcode,operand);
if(strcmp(opcode,"START")==0){
start=atoi(operand);
locctr=start;
fprintf(finter,"%d\t%s\t%s\t%s\n",locctr,label,opcode,operand);
fscanf(fin,"%s\t%s\t%s",label,opcode,operand);
}
while(strcmp(opcode,"END")!=0){
fprintf(finter,"%d\n",locctr);

if(strcmp(label,"**")!=0)
fprintf(fsym,"%s\t%d\n",label,locctr);
fscanf(fop,"%s\t%s",code,mne);
while(fscanf(fop, "%s\t%s", code, mne) == 2){
if(strcmp(opcode,code)==0){
locctr=locctr+3;
break;
}

fscanf(fop,"%s\t%s",code,mne);
}

fclose(fop);
if(strcmp(opcode,"WORD")==0)
locctr=locctr+3;
else if(strcmp(opcode,"RESW")==0)
locctr=locctr+(3*atoi(operand));
else if(strcmp(opcode,"RESB")==0)
locctr=locctr+atoi(operand);
else if(strcmp(opcode,"BYTE")==0)
locctr++;
else
printf("error");
fprintf(finter,"\t%s\t%s\t%s\n",label,opcode,operand);
fscanf(fin,"%s\t%s\t%s",label,opcode,operand);

}
fprintf(finter,"%d\t%s\t%s\t%s",locctr,label,opcode,operand);

fclose(fin);
fclose(fop);
fclose(finter);
fclose(fsym);
}































