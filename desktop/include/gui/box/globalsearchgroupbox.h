#ifndef GLOBALSEARCHGROUPBOX_H
#define GLOBALSEARCHGROUPBOX_H

#include <QGroupBox>

namespace Ui {
class GlobalSearchGroupBox;
}

namespace gui::box {

class GlobalSearchGroupBox : public QGroupBox
{
    Q_OBJECT

public:
    explicit GlobalSearchGroupBox(
        int            groupId,
        const QString &groupNameText,
        QWidget       *parent = nullptr
    );
    ~GlobalSearchGroupBox();

    [[ nodiscard ]]
    int groupId() const noexcept;

signals:
    void globalSearchGroupBoxClicked(int groupId, const QString &groupNameText);

protected:
    void mousePressEvent(QMouseEvent *mouseEvent)   override;
    void mouseReleaseEvent(QMouseEvent *mouseEvent) override;

private:
    Ui::GlobalSearchGroupBox *ui;
    int                       groupId_;
};

} // box

#endif // GLOBALSEARCHGROUPBOX_H
