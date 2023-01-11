#include <stdio.h>
#include <stdlib.h>
int matrice[9][9],x,row,col,num,startRow,startCol,j;
char formatPrintfnum[] = "%d ",linie[] = "\n";
int main(){
	FILE *fptr;
	fptr = fopen("date.in","r");
	for(int i = 0; i<9; i++){
		for(int j = 0; j < 9; j++){
			fscanf(fptr,"%d",&x);
			matrice[i][j] = x;
		}
	}
	__asm__
	(
        "pusha;"
        "jmp begin;"

	    "af:;"
            "lea matrice,%edi;"
            "xorl %ecx,%ecx;"

        "forii:;"
            "cmp $9,%ecx;"
            "je stop;"
            "xorl %esi,%esi;"
        
        "forjj:;"
            "cmp $9,%esi;"
            "je cont_forii;"

            "movl %ecx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl %esi,%eax;"

            "pushl %ecx;"
            "pushl (%edi,%eax,4);"
            "pushl $formatPrintfnum;"
            "call printf;"
            "popl %ebx;"
            "popl %ebx;"
            "popl %ecx;"

            "incl %esi;"
            "jmp forjj;"

        "cont_forii:;"
            "pushl %ecx;"
            "pushl $linie;"
            "call printf;"
            "popl %ebx;"
            "popl %ecx;"
            "incl %ecx;"
            "jmp forii;"

        "stop:;"
            "movl $1,%eax;"
            "xorl %ebx,%ebx;"
            "int $0x80;"

        "verificare:;"
            "pushl %esi;"
            "pushl %ebp;"
            "movl %esp,%ebp;"
            "lea matrice,%edi;"
            "movl 12(%ebp),%eax;"
            "movl %eax,row;"
            "movl 16(%ebp),%eax;"
            "movl %eax,col;"
            "movl 20(%ebp),%eax;"
            "movl %eax,num;"
            "xorl %ecx,%ecx;"

        "for1:;"
            "cmp $9,%ecx;"
            "je cont_ver;"

            "movl row,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl %ecx,%eax;"
            "movl (%edi,%eax,4),%edx;"

            "cmp num,%edx;"
            "je fals;"

            "movl %ecx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl col,%eax;"
            "movl (%edi,%eax,4),%edx;"

            "cmp num,%edx;"
            "je fals;"

            "incl %ecx;"
            "jmp for1;"

        "cont_ver:;"
            "xorl %edx,%edx;"
            "movl row,%eax;"
            "movl $3,%ebx;"
            "divl %ebx;"
            "movl row,%eax;"
            "subl %edx,%eax;"
            "movl %eax,startRow;"
            
            "xorl %edx,%edx;"
            "movl col,%eax;"
            "movl $3,%ebx;"
            "divl %ebx;"
            "movl col,%eax;"
            "subl %edx,%eax;"
            "movl %eax,startCol;"

            "xorl %ecx,%ecx;"

        "fori:;"
            "cmp $3,%ecx;"
            "je adv;"
            "xorl %esi,%esi;"
        
        "forj:;"
            "cmp $3,%esi;"
            "je cont_fori;"

            "movl startRow,%eax;"
            "addl %ecx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl startCol,%eax;"
            "addl %esi,%eax;"

            "movl (%edi,%eax,4),%eax;"
            "cmp num,%eax;"
            "je fals;"

            "incl %esi;"
            "jmp forj;"

        "cont_fori:;"
            "incl %ecx;"
            "jmp fori;"

        "fals:;"
            "movl $0,%eax;"
            "jmp final_verificare;"

        "adv:;"
            "movl $1,%eax;"
            "jmp final_verificare;"

        "final_verificare:;"
            "popl %ebp;"
            "popl %esi;"
            "ret;"

        "bk:;"
            "pushl %esi;"
            "pushl %ebp;"
            "movl %esp,%ebp;"
            "movl 12(%ebp),%edx;"
            "movl 16(%ebp),%esi;"

            "lea matrice,%edi;"
            "cmp $8,%edx;"
            "jne cont_bk1;"
            "cmp $9,%esi;"
            "je af;"
        
        "cont_bk1:;"
            "cmp $9,%esi;"
            "jne cont_bk2;"
            "addl $1, %edx;"
            "xorl %esi,%esi;"

        "cont_bk2:;"
            "pushl %edx;"
            "movl %edx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl %esi,%eax;"
            "movl (%edi,%eax,4),%ebx;"
            "popl %edx;"
            "cmp $0,%ebx;"
            "je cont_bk3;"

            "movl %esi,%eax;"
            "incl %eax;"
            "pushl %edx;"
            "pushl %eax;"
            "pushl %edx;"
            "call bk;"
            "popl %ebx;"
            "popl %ebx;"
            "popl %edx;"

        "cont_bk3:;"
            "xorl %ecx,%ecx;"
            "incl %ecx;"
        
        "for_bk:;"
            "cmp $10,%ecx;"
            "je final_bk;"

            "pushl %ecx;"
            "pushl %edx;"
            "pushl %ecx;"
            "pushl %esi;"
            "pushl %edx;"
            "call verificare;"
            "popl %ebx;"
            "popl %ebx;"
            "popl %ebx;"
            "popl %edx;"
            "popl %ecx;"
            
            "cmp $0,%eax;"
            "je cont_for;"
            
            "lea matrice,%edi;"
            "pushl %edx;"
            "movl %edx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl %esi,%eax;"
            "movl %ecx,(%edi,%eax,4);"
            "popl %edx;"

            "movl %esi,%eax;"
            "incl %eax;"
            "pushl %ecx;"
            "pushl %edx;"
            "pushl %eax;"
            "pushl %edx;"
            "call bk;"
            "popl %ebx;"
            "popl %ebx;"
            "popl %edx;"
            "popl %ecx;"
        
        "cont_for:"
            "pushl %edx;"
            "lea matrice,%edi;"
            "movl %edx,%eax;"
            "movl $9,%ebx;"
            "mull %ebx;"
            "addl %esi,%eax;"
            "movl $0,(%edi,%eax,4);"
            "popl %edx;"

            "incl %ecx;"
            "jmp for_bk;"

        "final_bk:;"
            "popl %ebp;"
            "popl %esi;"
            "ret;"

        "begin:;"
            "pushl $0;"
            "pushl $0;"
            "call bk;"
            "popl %ebx;"
            "popl %ebx;"

        "popa;"
	);
	return 0;
}