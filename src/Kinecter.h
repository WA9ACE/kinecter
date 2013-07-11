class Kinecter
{
public:
	Kinecter(void);
	~Kinecter(void);

	void start();
	void webSocketReady();

private:
	int port;
};
