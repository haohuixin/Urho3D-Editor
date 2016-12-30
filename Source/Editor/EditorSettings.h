#pragma once

#include <Urho3D/Core/Context.h>
#include <QSettings>
// #include <Urho3D/Engine/Engine.h>
// #include <QTimer>
// #include <QWidget>

namespace Urho3DEditor
{

class EditorSettings : public Urho3D::Object
{
    URHO3D_OBJECT(EditorSettings, Urho3D::Object);

public:
    static const QString LAST_DIRECTORY;
    static const QString RECENT_PROJECTS;

public:
    /// Construct.
    EditorSettings(Urho3D::Context* context);
    /// Get last directory.
    QString GetLastDirectory() const { return settings_.value(LAST_DIRECTORY).toString(); }
    /// Set last directory.
    void SetLastDirectory(const QString& value);
    /// Get recent projects.
    QStringList GetRecentProjects() const { return settings_.value(RECENT_PROJECTS).toStringList(); }
    /// Add recent project.
    void AddRecentProject(const QString& name);

private:
    /// Settings.
    QSettings settings_;

};

}

