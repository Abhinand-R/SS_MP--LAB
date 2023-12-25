/*#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main()
{
printf("hao");
int len=18,start_address=0,flag=0,locctr=0;

FILE *finput,*foptab,*finter,*fsymtab,*fassembly,*fobject,*fobject1;
finput = fopen("input.txt","r");
foptab = fopen("optab.txt","r");
finter = fopen("inter.txt","r");
fsymtab = fopen("symtab.txt","r");
fassembly=fopen("assembly.txt","w");
fobject=fopen("object.txt","w");


char label[20],opcode[20],operand[20],optabval[20],optabhexcode[20],start[20],symlabel[20],symadd[20],address[20];
fscanf(finter,"%s %s %s %s",address,label,opcode,operand);
printf("%s %s %s %s",address,label,opcode,operand);
//start_address=atoi(operand);
strcpy(start,operand);
if(strcmp(opcode,"START")==0) {
//locctr=atoi(operand);
fprintf(fassembly,"**\t%s\t%s\t**\t%s\t\n",label,opcode,operand);
fprintf(fobject,"H^%s^00%s^0000%d\n",label,operand,len);
}

fscanf(finter,"%s %s %s %s",address,label,opcode,operand);
//printf("%s %s %s %s",address,label,opcode,operand);
//printf("H^%s^%s^%d\nT^00%s^",label,start,len,start);


//fscanf(finput,"%s %s %s",label,opcode,operand);
while(strcmp(opcode,"END")!=0) {
//locctr=atoi(operand);
if(strcmp(label,"**")==0) {
while(!feof(foptab)) {
fscanf(foptab,"%s%s",optabval,optabhexcode);
if(strcmp(opcode,optabval)==0) {
//fscanf(fsymtab,"%s\t%d\n",symlabel,symadd);
while(!feof(fsymtab)){
fscanf(fsymtab,"%s\t%s\n",symlabel,symadd);
if(strcmp(operand,symlabel)==0){
strcat(optabhexcode,symadd);
fprintf(fassembly,"%s\t%s\t%s\t%s\t%s\n",address,label,opcode,operand,optabhexcode);
  fprintf(fobject,"T^00%s^03^%s\n",address,optabhexcode);
  flag=1;
break;
}
}
}
if(flag==1){
break;
}
}

}
else if(strcmp(opcode,"WORD")==0) {
//fscanf(fsymtab,"%s %s",symlabel,symadd);
  fprintf(fassembly,"%s\t%s\t%s\t%s\t0000%s\n",address,label,opcode,operand,operand);
  fprintf(fobject,"T^00%s^03^00000%s\n",address,operand);
  }
  else if(strcmp(opcode,"RESW")==0) {
  fprintf(fassembly,"%s\t%s\t%s\t%s\t**\n",address,label,opcode,operand);
  }
}

fclose(finput);
fclose(foptab);
fclose(finter);
fclose(fsymtab);
fclose(fassembly);
fclose(fobject);
}*/





#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void main() {
    int len = 18, flag = 0, locctr = 0;
    FILE* finput, * foptab, * finter, * fsymtab, * fassembly, * fobject;
    finput = fopen("input.txt", "r");
    foptab = fopen("optab.txt", "r");
    finter = fopen("inter.txt", "r");
    fsymtab = fopen("symtab.txt", "r");
    fassembly = fopen("assembly.txt", "w");
    fobject = fopen("object.txt", "w");
    char label[20], opcode[20], operand[20], optabval[20], optabhexcode[20], start[20], symlabel[20], symadd[20], address[20];
    fscanf(finter, "%s %s %s %s", address, label, opcode, operand);
    strcpy(start, operand);
    if (strcmp(opcode, "START") == 0) {
        fprintf(fassembly, "**\t%s\t%s\t**\t%s\t\n", label, opcode, operand);
        fprintf(fobject, "H^%s^00%s^0000%d\n", label, operand, len);
    }
    fscanf(finter, "%s %s %s %s", address, label, opcode, operand);
    while (strcmp(opcode, "END") != 0) {
        if (strcmp(label, "**") == 0) {
            while (!feof(foptab)) {
                fscanf(foptab, "%s%s", optabval, optabhexcode);
                if (strcmp(opcode, optabval) == 0) {
                    while (!feof(fsymtab)) {
                        fscanf(fsymtab, "%s\t%s", symlabel, symadd);                     
                        if (strcmp(operand, symlabel) == 0) {
                            strcat(optabhexcode, symadd);
                            fprintf(fassembly, "%s\t%s\t%s\t%s\t%s\n", address, label, opcode, operand, optabhexcode);
                            fprintf(fobject, "T^00%s^03^%s\n", address, optabhexcode);
                            flag = 1;
                            break;
                        }
                    }
                }
                if (flag == 1) {
                    break;
                }
            }
        } else if (strcmp(opcode, "WORD") == 0) {
            fprintf(fassembly, "%s\t%s\t%s\t%s\t0000%s\n", address, label, opcode, operand, operand);
            fprintf(fobject, "T^00%s^03^00000%s\n", address, operand);
        } else if (strcmp(opcode, "RESW") == 0) {
            fprintf(fassembly, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);
        }
        fscanf(finter, "%s %s %s %s", address, label, opcode, operand);
    }
    	fprintf(fassembly, "%s\t%s\t%s\t**\t00%s\n", address, label, opcode, operand);
	fprintf(fobject, "E^00%s\n", start);
    fclose(finput);
    fclose(foptab);
    fclose(finter);
    fclose(fsymtab);
    fclose(fassembly);
    fclose(fobject);
}








/*

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {

    int len = 18, flag = 0, locctr = 0;

    FILE* finput, * foptab, * finter, * fsymtab, * fassembly, * fobject;

    finput = fopen("input.txt", "r");
    foptab = fopen("optab.txt", "r");
    finter = fopen("inter.txt", "r");
    fsymtab = fopen("symtab.txt", "r");
    fassembly = fopen("assembly.txt", "w");
    fobject = fopen("object.txt", "w");

    char label[20], opcode[20], operand[20], optabval[20], optabhexcode[20], start[20], symlabel[20], symadd[20], address[20];

    fscanf(finter, "%s %s %s %s", address, label, opcode, operand);

    printf("%s %s %s %s", address, label, opcode, operand);

    // start_address=atoi(operand);

    strcpy(start, operand);

    if (strcmp(opcode, "START") == 0) {

        // locctr=atoi(operand);

        fprintf(fassembly, "**\t%s\t%s\t**\t%s\t\n", label, opcode, operand);

        fprintf(fobject, "H^%-6s^00%s^0000%X\n", label, operand, len);

    }

    fscanf(finter, "%s %s %s %s", address, label, opcode, operand);

    // printf("%s %s %s %s",address,label,opcode,operand);

    // printf("H^%s^%s^%lX\nT^00%s^");

    // fscanf(finput,"%s %s %s",label,opcode,operand);

    while (strcmp(opcode, "END") != 0) {

        // locctr=atoi(operand);

        if (strcmp(label, "**") == 0) {

            while (!feof(foptab)) {

                fscanf(foptab, "%s%s", optabval, optabhexcode);

                if (strcmp(opcode, optabval) == 0) {

                    // fscanf(fsymtab,"%s\t%d\n",symlabel,symadd);

                    while (!feof(fsymtab)) {

                        fscanf(fsymtab, "%s\t%s", symlabel, symadd);

                        if (strcmp(operand, symlabel) == 0) {

                            strcat(optabhexcode, symadd);

                            fprintf(fassembly, "%s\t%s\t%s\t%s\t%s\n", address, label, opcode, operand, optabhexcode);

                            fprintf(fobject, "T^00%s^03^%s\n", address, optabhexcode);

                            flag = 1;

                            break;

                        }

                    }

                }

                if (flag == 1) {

                    break;

                }

            }

        } else if (strcmp(opcode, "WORD") == 0) {

            // fscanf(fsymtab,"%s %s",symlabel,symadd);

            fprintf(fassembly, "%s\t%s\t%s\t%s\t0000%s\n", address, label, opcode, operand, operand);

            fprintf(fobject, "T^00%s^03^%06lX\n", address, strtol(operand, NULL, 10));

        } else if (strcmp(opcode, "RESW") == 0) {

            fprintf(fassembly, "%s\t%s\t%s\t%s\t**\n", address, label, opcode, operand);

        }

        fscanf(finter, "%s %s %s %s", address, label, opcode, operand);

    }

    // Add END record
    fprintf(fobject, "E^00%lX\n", strtol(start, NULL, 10));

    fclose(finput);
    fclose(foptab);
    fclose(finter);
    fclose(fsymtab);
    fclose(fassembly);
    fclose(fobject);

}*/


