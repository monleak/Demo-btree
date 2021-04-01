#include "cmake-btree/inc/btree.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <string.h>

#define NUMBER_LEN 20

void delete_newline(char *s) {
	int len = strlen(s);
	while(s[len -1] == '\n' || s[len -1] == '\r') {
		s[len -1] = '\0';
		len--;
	}
}

void add_contact(BTA *root) {
	char phone[NUMBER_LEN+1];
	char name[ZKYLEN+1];
	printf("name: ");
	fgets(name, ZKYLEN, stdin);
	printf("phone: ");
	fgets(phone, NUMBER_LEN, stdin);
	delete_newline(name);
	delete_newline(phone);
	// printf("\nname: \n%sphone: %s\n", name, phone);
	int ret = btins(root, name, phone, strlen(phone)+1);
	if(ret != 0) {
		printf("Insert error!\n");
	}
}

void list_contact(BTA *root) {
	//Dua ve dau
	btpos(root, ZSTART);
	//Lap
	char buf[NUMBER_LEN+1];
    char key[ZKYLEN];
    int  status,size;

    printf("All contact:\n");
    for(;;) {
    	status = btseln(root, key, buf,NUMBER_LEN+1,&size);
    	if (status == 0) {
        	printf("Name: '%s' - Number: '%s'\n",key,buf);
    	}else {
    		break;
    	}
	}
}

int main(int argc, char* argv[]) {
	if(argc < 2) 
	{
		printf("usage: ./phone-bt book.bt\n");
		return 1;
	}

	//Mo fole 

	BTA *root = NULL;
	root = btopn(argv[1], 0, FALSE);

	if(!root) {
		root = btcrt(argv[1], 0, FALSE);
		if(!root) {
			printf("Cannot open or create!\n");
		}
	}

	// 1.them
	// 2.in 
	// 3.thoat

	for(;;) {
		printf("1.Them\n2.in\n3.Thoat\n");
		int cmd = 0;
		printf("Lenh: ");
		scanf("%d%*c", &cmd);
		// __fpurge(stdin);
		if(cmd == 1) {
			add_contact(root);
		} else if(cmd == 2) {
			list_contact(root);
		} else if(cmd == 3) {
			break;
		}
	}

	btcls(root);
	return 0;
}