/** \file view.h
 * \author NICOL Pauline SERVOIN Arnaud VANACKER Chloé
 * \date 29/11/2016
 */

#ifndef VIEW_H
#define VIEW_H

#include"controller.h"
#include "header.h"
#include "project.h"
#include "videosurface.h"
#include "mysubwindows.h"


/** \namespace Ui
 *
 * \brief Espace de nommage regroupant les outils composants l'interface Ui
 * qui nous permet de gérer la vue
 */


namespace Ui
{
class View;
}


/** \class View view.h */
/** \brief Classe permettant de gérer notre vue et ici de gérer notre QMainWindow
 */

class View : public QMainWindow
{
    Q_OBJECT

public:

    /** Constructeur de la classe View */
    explicit View(QWidget *parent = 0);
    /** Destructeur de la classe View */
    ~View();

private:
    Ui::View *ui; /**< La vue a un pointeur vers le formulaire Ui */

public:
    Controller* controller; /**< La classe Vue a comme attribut un pointeur vers le Controller */

public:

    QMdiArea* main_area;/**< Declaration de l'aire principal de la fenetre principale   */

public:
    std::vector<MySubWindows*> sub_windows;/**< Tableau de pointeurs vers MySubWindows, les sous fenetres de l'application */
    QMessageBox* message_box; /**< La QMessageBox qui contiendra les messages à faire passer à l'utilisateur */
public:

    /**
     * \brief Fonction qui mets nos actions à leur état initial
     */
    void initial_actions_state();
    /**
     * \brief Fonction qui gère l'affichage des QMessagebox
     * \param title : variable QString qui sera le titre de la message_box
     * \param content : variable QString qui sera le contenu de la message_box
     *
     */
    void display_message_box(QString title, QString content);

    /**
     * \brief Fonction qui ouvre une open_box pour les images
     * \return La liste des noms de fichiers des images à ouvrir en QStringList
     */
    QStringList display_open_box_image();

    /**
     * \brief Fonction qui ouvre une open_box pour les videos
     * \return La liste des noms de fichiers des videos à ouvrir en QStringList
     */
    QStringList display_open_box_video();

    /**
     * \brief Fonction qui ouvre une save_as_box pour saisir le nom sous lequel on veut
     * sauvegarder le fichier
     * \return Le nom sous lequel on sauvegarde le fichier en QString
     */
    QString display_save_as_box();

    /**
     * \brief Fonction qui gère l'ajout de sous fenetre dans le tableau de sous fenetre
     */
    void add_sub_window();

    /**
     * \brief Fonction qui affiche la sous fenetre désirée
     * \param index_of_sub_window: index de la sub_window dans le vecteur de sub_window
     */
    void display_sub_window(int index_of_sub_window);

    /**
     * \brief Fonction qui cache la sous fenetre désirée
     * \param index_of_sub_window: index de la sub_window dans le vecteur de sub_window
     */
    void hide_sub_window(int index_of_sub_window);

    /**
     * \brief Fonction qui actualise la sub_window désirée
     * \param index_of_sub_window: index de la sub_window dans le vecteur de sub_window
     */
    void refresh_sub_window(int index_of_sub_window);



//Déclaration des actions
private:
    QAction* open_action_image;/**<   Action qui nous permet d'ouvrir une image  */
    QAction* open_action_video;/**<   Action qui nous permet d'ouvrir une video  */
    QAction* save_action;/**< Action qui nous permet d'enregistrer une image dans un fichier existant*/
    QAction* save_as_action;/**<  Action qui nous permet d'enregistrer une image dans un nouveau fichier */
    QAction* convert_action;/**< Action qui nous permet permet de convertir une image ou une video en noir et blanc  */
    QAction* assemble_action;/**< Action qui nous permet de faire un montage de photos ou de videos  */
    QAction* help_action;/**< Action qui nous permet d'ouvrir un message d'aide de notre logiciel */
    QAction* about_action;/**<  Action qui nous permet d'ouvrir un message contenant les auteurs de ce logiciel  */

    /**
     * \brief Création des actions
     */
    void create_actions();

    /**
     * \brief Libération de la mémoire prise par les actions
     */
    void delete_actions();

//Déclaration des SLOTS: fonction activées par les actions
private slots:
    /**
     * \brief Fonction d'ouverture des images
     */
    void open_image();

    /**
     * \brief Fonction d'ouverture des videos
     */
    void open_video();

    /**
     * \brief Fonction de sauvegarde des images dans un fichier existant
     */
    void save();

    /**
     * \brief Fonction de sauvergarde des images dans un nouveau fichier
     */
    void save_as();

    /**
     * \brief Fonction de conversion des images et videos en noir et blanc
     */
    void convert_all();

    /**
     * \brief Fonction de montage photo ou vidéos
     */
    void assemble();

    /**
     * \brief Fonction d'affichage de l'aide
     */
    void help();

    /**
     * \brief Fonction d'affichage du a propos
     */
    void about();

//Déclaration des menus
private:
    QMenu* file_menu; /**< Menu fichier */
    QMenu* action_menu;/**< Menu action */
    QMenu* help_menu;/**<  Menu help */
    QMenu* about_menu;/**< Menu about   */

    /**
     * \brief Creation des menus
     */
    void create_menu();

    /**
     * \brief Libération de la mémoire des menus
     */
    void delete_menus();

private:

        //Creation des barres d'outils
        QToolBar* file_tool_bar;/**<  Barre de menu de fichiers */
        QToolBar* modification_tool_bar;/**< Barre de menu d'action*/

        /**
         * \brief Creation des Barres de menu
         */
        void create_tool_bar();

        /**
         * \brief Libération de la mémoire des barres d'outils
         */
        void delete_tool_bars();

};


#endif // VIEW_H
