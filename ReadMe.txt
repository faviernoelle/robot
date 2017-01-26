ReadMe
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
Auteur: Noelle FAVIER
Date: 2017 01 06
%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

---------------------------------------------------------------------------------------------------
COMMENT INSTALLER GIT
---------------------------------------------------------------------------------------------------
* Installer git depuis : https://git-scm.com/
* Vous pouvez utiliser git via une ligne de commande (shell) oubien
en installant une interface (recommand�), TortoiseGit : https://tortoisegit.org/
* Demander les acc�s/permissions du dossier Github � Noelle Favier. 
(NB : cr�er au pr�alable un compte sur Github : https://github.com/)
* Cloner le repository :
-- clique droit sur un r�pertoire, s�lectionner "Git Clone"
-- adresse : https://github.com/faviernoelle/robot.git
* Quelques fonctions utiles de GIT :
-- Pour faire une sauvegarde locale : clique droit --> "git commit"
-- Pour envoyer les sauvegardes locales vers le server : clique droit --> "git push"
-- Pour mettre � jour son r�pertoire local depuis le server : clique droit --> "git pull"
-- Pour voir l'arbre de r�visions : clique droit --> "show log"
-- Pour voir le diff des fichiers : 
-- Pour cr�er un tag (photo du code � un moment t) : clique droit --> "git tag"


---------------------------------------------------------------------------------------------------
IF THE ICONS OF TURTOISE GIT DOES NOT APPEAR
---------------------------------------------------------------------------------------------------
* Open regedit
* Path : HKEY_LOCAL_MACHINE\SOFTWARE\Microsoft\Windows\CurrentVersion\Explorer\ShellIconOverlayIdentifiers
* Remove/delete all SkyDrive/OneDrive keys. You may need to take ownership of the keys one by one 
and give your user full control if you receive an error while trying to delete the keys.
* Press Ctrl+Shift+Esc and restart "Windows Explorer" (Optionally restart computer)
* All git/svn overlay icons are now visible !

----------------------------------------------------------------------------------------------------
LOGS
----------------------------------------------------------------------------------------------------
2017 01 26
* Correction de Windows si les icones de GITTurtoise n'apparaissent pas

2017 01 06
* Cr�ation du fichier ReadMe.txt
* Mise � jour de comment installer GIT

