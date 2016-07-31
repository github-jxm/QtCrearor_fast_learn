#include <QLocalSocket>
#include <stdlib.h>
#include <unistd.h>
 
//int main(int argc, char **argv)
int main()
{
    
    QLocalSocket ls;
    ls.connectToServer("localserver-test");
    srandom(1000);
 
    if (ls.waitForConnected()){
        while (1){
            QTextStream ts(&ls);
            ts << QString::number(random()) + "\nTTTTTTTTTT" + "\nXXXXXXXX";
            ts.flush();
            ls.waitForBytesWritten();
            sleep(1);
        }
    }
    return 0;
}

