switch (task) {
    case 1: {
        cout << "--- Задача 1 ---\n";
        bool isAuthorized, hasSubscription, isTrial, accountBlocked;
        cout << "isAuthorized hasSubscription isTrial accountBlocked (0/1): ";
        cin >> isAuthorized >> hasSubscription >> isTrial >> accountBlocked;
        bool access = isAuthorized && !accountBlocked && (hasSubscription || isTrial);
        if (access) cout << "Access allowed";
        else cout << "Access denied";
        break;
    }
    case 2: {
        cout << "--- Задача 2 ---\n";
        int loginLength, passwordLength;
        bool hasSpecialSymbol;
        cout << "loginLength passwordLength hasSpecialSymbol(0/1): ";
        cin >> loginLength >> passwordLength >> hasSpecialSymbol;
        if (loginLength < 5 || loginLength > 15) cout << "Login is too short or too long";
        else if (passwordLength < 8) cout << "Password is too short";
        else if (!hasSpecialSymbol) cout << "Special symbol required";
        else cout << "Registration successful";
        break;
    }
    case 3: {
        cout << "--- Задача 3 ---\n";
        int majorVersion, minorVersion;
        cin >> majorVersion >> minorVersion;
        if ((majorVersion > 2 || (majorVersion == 2 && minorVersion >= 5)) &&
            (majorVersion < 4 || (majorVersion == 4 && minorVersion <= 3))) {
            cout << "Supported";
        } else {
            cout << "Unsupported";
        }
        break;
    }
    case 4: {
        cout << "--- Задача 4 ---\n";
        int sizeMB;
        bool correctExtension, containsVirus;
        cout << "sizeMB correctExtension containsVirus (0/1): ";
        cin >> sizeMB >> correctExtension >> containsVirus;
        if (sizeMB > 25) cout << "File is too large";
        else if (!correctExtension) cout << "Unsupported file type";
        else if (containsVirus) cout << "Dangerous file";
        else cout << "Upload allowed";
        break;
    }
    case 5: {
        cout << "--- Задача 5 ---\n";
        int code;
        cin >> code;
        switch (code) {
            case 200: cout << "OK"; break;
            case 201: cout << "Created"; break;
            case 400: cout << "Bad Request"; break;
            case 401: cout << "Unauthorized"; break;
            case 404: cout << "Not Found"; break;
            case 500: cout << "Server Error"; break;
            default:  cout << "Unknown status";
        }
        break;
    }
    case 6: {
        cout << "--- Задача 6 ---\n";
        char cmd;
        cin >> cmd;
        switch (cmd) {
            case 'c': case 'C': cout << "commit"; break;
            case 'p': case 'P': cout << "push"; break;
            case 'l': case 'L': cout << "pull"; break;
            case 's': case 'S': cout << "status"; break;
            default:  cout << "Unknown Git command";
        }
        break;
    }
    case 7: {
        cout << "--- Задача 7 ---\n";
        int mode;
        bool testsPassed, compilerErrors;
        cout << "mode testsPassed compilerErrors (0/1): ";
        cin >> mode >> testsPassed >> compilerErrors;
        switch (mode) {
            case 1:
                if (!compilerErrors) cout << "Debug launch allowed";
                else cout << "Debug launch denied: compiler errors";
                break;
            case 2:
                if (!compilerErrors && testsPassed) cout << "Release launch allowed";
                else cout << "Release launch denied";
                break;
            case 3:
                if (!compilerErrors) cout << "Test launch allowed";
                else cout << "Test launch denied: compiler errors";
                break;
            default:
                cout << "Unknown build mode";
        }
        break;
    }
    case 10: {
        cout << "--- Задача 10 ---\n";
        int branchType;
        bool buildPassed, testsPassed, reviewApproved, hasConflicts;
        cout << "branchType (1-feature, 2-bugfix, 3-hotfix): ";cin >> branchType;
        cout << "buildPassed testsPassed reviewApproved hasConflicts (0/1): ";
        cin >> buildPassed >> testsPassed >> reviewApproved >> hasConflicts;

        string branchName;
        switch (branchType) {
            case 1: branchName = "feature"; break;
            case 2: branchName = "bugfix"; break;
            case 3: branchName = "hotfix"; break;
            default:
                cout << "Unknown branch type";
                return 0;
        }
        cout << "Branch: " << branchName << endl;

        bool accepted = false;
        string reason;

        switch (branchType) {
            case 1:
                if (buildPassed && testsPassed && reviewApproved && !hasConflicts) accepted = true;
                else {
                    if (hasConflicts) reason = "conflicts detected";
                    else if (!buildPassed) reason = "build failed";
                    else if (!testsPassed) reason = "tests failed";
                    else reason = "review not approved";
                }
                break;
            case 2:
                if (buildPassed && testsPassed && !hasConflicts) accepted = true;
                else {
                    if (hasConflicts) reason = "conflicts detected";
                    else if (!buildPassed) reason = "build failed";
                    else reason = "tests failed";
                }
                break;
            case 3:
                if (buildPassed && reviewApproved && !hasConflicts) accepted = true;
                else {
                    if (hasConflicts) reason = "conflicts detected";
                    else if (!buildPassed) reason = "build failed";
                    else reason = "review not approved";
                }
                break;
        }

        if (accepted) cout << "Pull Request accepted" << endl;
        else {
            cout << "Pull Request rejected" << endl;
            cout << "Reason: " << reason << endl;
        }
        break;
    }
    default:
        cout << "Нет такой задачи";
}

return 0;
