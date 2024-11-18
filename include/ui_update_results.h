#pragma once

namespace is
{
    enum UIActions
    {
        Nothing,
        Continue,
        Restart,
        LevelSelect,
        Title
    };

    struct UIUpdateResults
    {
        UIActions action = UIActions::Nothing;
        
        UIUpdateResults() = default;
        UIUpdateResults(UIActions uia) { action = uia; }
    };
}