#include "backend.h"
#include "createmaze.h"
#include "mazesolver.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

Backend::Backend(QObject *parent) : QObject(parent), m_mazeColumns(0), m_mazeRows(0)
{
}

int Backend::mazeColumns() const
{
    return m_mazeColumns;
}

int Backend::mazeRows() const
{
    return m_mazeRows;
}

QStringList Backend::mazeData() const
{
    return m_mazeData;
}

void Backend::generateMaze()
{
    CreateMaze createMaze(25,25);
    createMaze.run();
    loadMazeData("maze.txt");
}

void Backend::findWay()
{
    MazeSolver mazeSolver("maze.txt");
    mazeSolver.run();
    loadMazeData("solution.txt");
}

void Backend::loadMazeData(const QString &filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qWarning() << "Cannot open file:" << filePath;
        return;
    }

    QTextStream in(&file);
    m_mazeData.clear();
    m_mazeRows = 0;
    while (!in.atEnd())
    {
        QString line = in.readLine();
        m_mazeColumns = line.size();
        for (const QChar &c : line)
        {
            m_mazeData.append(c);
        }
        m_mazeRows++;
    }
    file.close();
    emit mazeDataChanged();
}
