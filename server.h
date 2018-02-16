#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include <client.h>

class Server : public QObject
{
	Q_OBJECT

public:
	Server();
	~Server();
	void print_list();
	QString get_win_prop(unsigned long window, unsigned long atom);
	QVector<unsigned long> get_client_list();
	void sync_list();

signals:
	void clientListUpdated();

public slots:
	int clientListChanged(unsigned long atom_name);

private:
	// X11 Atoms (initiated in constructor).
	unsigned long m_utf8_string;
	unsigned long m_net_client_list;
	unsigned long m_net_wm_name;
};

#endif	// SERVER_H
