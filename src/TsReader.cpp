#include "stdio.h"
#include <iostream>
#include "stdlib.h"
#include "string.h"
#include "fcntl.h"
#include "TsReader.h"
using namespace std;
TsReader::TsReader()
{
	m_fileName = NULL;
	m_size = 0;
	m_fd = -1;

}
TsReader::TsReader(char * fileName)
{
	InitTsReader();
	if (configTsReader(fileName) == -1)
		cout <<"config TsReader fail!"<<endl;
}
TsReader::~TsReader()
{
	fileClose();
	if (m_fileName != NULL)
		delete(m_fileName);
	m_fileName = NULL;
	m_size = 0;
}
void TsReader::InitTsReader(){
	m_fileName = NULL;
	m_size = 0;
	m_fd = -1;
}
int TsReader::configTsReader(char * fileName)
{
	fileClose();
	if (m_fileName != NULL){
		delete(m_fileName);
		m_fileName = NULL;
	}
	m_size = 0;

	if (fileName == NULL){
		cout<< "fileName is empty"<< endl;
		goto fail;
	}
	if (access(fileName,F_OK | R_OK)){
		cout << "file: "<< fileName<< "not exist!"<<endl;
	
		goto fail;
	}
	m_fileName = (char *)new char[strlen(fileName)+1];
	memcpy(m_fileName , fileName, strlen(fileName)+1);

	if (fileOpen() == -1)
		cout <<" open file:"<< m_fileName<< " fail!"<< endl;
	return 0;
fail :
	return -1;

}
int TsReader::fileOpen()
{
	if (m_fileName == NULL){

		cout<< "Please config the TsFile !"<< endl;
		return -1;
	}
	m_fd = open (m_fileName, O_RDONLY);
	return m_fd;
}
int TsReader::fileClose()
{
	if (m_fd != -1)
		close(m_fd);
	m_fd = -1;
	return 0;
}
int TsReader::fileRead(void * buf, unsigned &size)
{
	if (m_fd ==  -1){
		cout <<"file not open !" <<endl;
		return -1;
	}
	size = read(m_fd, buf, size);
	return size;
}
int TsReader::getCurrentOffset()
{
	if (m_fd == -1){
		cout << "file not open !" <<endl;
		return -1;
	}
	return lseek(m_fd, 0, SEEK_CUR);
}
