#ifndef TSREADER_H
#define TSREADER_H
class TsReader
{
	private:
		char * m_fileName;
		unsigned long long m_size;
		int m_fd ;
		int fileOpen();
		int fileClose();
		void InitTsReader();
	public:
		TsReader(char*);
		TsReader();
		~TsReader();
		int configTsReader(char *);
		int fileRead(void*, unsigned &);
		int getCurrentOffset();
};

#endif // TSREADER_H
