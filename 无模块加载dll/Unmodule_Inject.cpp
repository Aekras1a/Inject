// Unmodule_Inject.cpp : �������̨Ӧ�ó������ڵ㡣
//
#include "stdafx.h"
#include<Windows.h>
#include"UnModuleInject.h"

int _tmain(int argc, _TCHAR* argv[])
{


	//ȷ�������� �Ƕ���λ�ģ�
	//ȷ��Ŀ������Ƕ���λ��

	//HMODULE h = LoadLibraryA("C:\\Users\\storm\\Desktop\\Desktop\\Desktop\\Unmodule_Inject\\Debug\\Dll1.dll");
	char szFileName[] = "C:\\Users\\storm\\Desktop\\Desktop\\Desktop\\Unmodule_Inject\\Debug\\Dll1.dll";
	//char szFileName[] ="C:\\Users\\storm\\Desktop\\Desktop\\Desktop\\Unmodule_Inject\\x64\\Debug\\Dll1.dll";
	DWORD dwProcessId = 8752;

	HANDLE hFile = CreateFileA(szFileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, 0, NULL);
	if(hFile != INVALID_HANDLE_VALUE)
	{
		DWORD filesize = GetFileSize(hFile, NULL);
		if(filesize != NULL)
		{
			UCHAR *buffer = new UCHAR[filesize];        //���һλΪ'\0',C-Style�ַ����Ľ�������
			DWORD readsize;
			if(ReadFile(hFile, buffer, filesize, &readsize, NULL) == TRUE && readsize == filesize)
			{
				HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, dwProcessId);
				//ModuleLessInject(hProcess, buffer, filesize, NULL, NULL, NULL);
				//Wow64ModuleLessInjectToX64(hProcess, buffer, filesize, NULL, NULL, NULL);

				X64ModuleLessInjectToWow64(hProcess, buffer, filesize, NULL, NULL, NULL);
			}
		}
	}
	
	system("pause");
	return 0;
}

