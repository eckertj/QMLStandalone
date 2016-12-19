
#include <QtWidgets>
#include <QTimer>
#include <QQmlEngine>
#include <QQuickView>


class MainWindow : public QQuickView
{
		Q_OBJECT

	public:
		/// constructor
		MainWindow(QWindow *parent = 0, QQmlEngine* engine = 0);

		/// destructor
		~MainWindow();

	protected slots:
		void handleSceneGraphInitialized();

	protected:
		bool eventFilter(QObject*, QEvent*);

		void keyPressEvent(QKeyEvent * event) override;


};


