#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QStringList>
#include <QVector>

class Backend : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int mazeColumns READ mazeColumns NOTIFY mazeDataChanged)
    Q_PROPERTY(int mazeRows READ mazeRows NOTIFY mazeDataChanged)
    Q_PROPERTY(QStringList mazeData READ mazeData NOTIFY mazeDataChanged)

public:
    explicit Backend(QObject *parent = nullptr);

    int mazeColumns() const;
    int mazeRows() const;
    QStringList mazeData() const;

public slots:
    void generateMaze();
    void findWay();

signals:
    void mazeDataChanged();

private:
    int m_mazeColumns;
    int m_mazeRows;
    QStringList m_mazeData;

    void loadMazeData(const QString &filePath);
};

#endif // BACKEND_H
