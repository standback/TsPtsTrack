#ifndef TSPTSPARSER_H
#define TSPTSPARSER_H
enum PARSER_STATUS{
	PARSER_STATUS_RUNNING,
	PARSER_STATUS_STOP,
	PARSER_STATUS_PAUSED,
};
class TsPtsParser{
	private:
		PARSER_STATUS status;
	public:
		void start();
		void paused();
		void stop();
		setParserFile(char*);
};
#endif //TSPTSPARSER_H
