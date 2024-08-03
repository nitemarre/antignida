#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
main(){
	if (fopen("hcu.txt", "r")) {
		char* files[] = {"shell.txt", "shell1.txt", "hcu.txt", "hcu1.txt", "hlm.txt", "hlm1.txt", "hcu_node.txt", "hcu_node1.txt", "hlm_node.txt", "hlm_node1.txt"};
		system("cd %AppData%\\Microsoft\\Windows\\Start Menu\\Programs\\Startup & dir > %cd%\\shell1.txt");
		system("reg query HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run > hcu1.txt");
		system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run > hlm1.txt");
		system("reg query HKEY_CURRENT_USER\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run > hcu_node1.txt");
		system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run > hlm_node1.txt");
		fpos_t file_size = {0};
		fpos_t file_size2 = {0};
		int f_z1;
		int f_z;
		FILE* fd;
		for (int i = 0, a = 0; i < 4; i++){
			fd = fopen(files[a], "rb");
			fseek(fd, 0, SEEK_END);
			fgetpos(fd, &file_size);
			fclose(fd);
			fd = fopen(files[a+1], "rb");
			fseek(fd, 0, SEEK_END);
			fgetpos(fd, &file_size2);
			fclose(fd);
			f_z = file_size.__value;
			f_z1 = file_size2.__value;
			if (f_z != f_z1) goto error;
			a++;
			a++;
		}

}

else{
	system("cd %AppData%\\Microsoft\\Windows\\Start Menu\\Programs\\Startup & dir > %cd%\\shell.txt");
	system("reg query HKEY_CURRENT_USER\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run > hcu.txt");
	system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run > hlm.txt");
	system("reg query HKEY_CURRENT_USER\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run > hcu_node.txt");
	system("reg query HKEY_LOCAL_MACHINE\\SOFTWARE\\Wow6432Node\\Microsoft\\Windows\\CurrentVersion\\Run > hlm_node.txt");
}
return 0;

error:
	MessageBox(NULL, "unmatch", "error", MB_OK);
}
