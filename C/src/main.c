#include <stdio.h>
#include <stdlib.h>
#include "OGame.h"


int main()
{PREZ
    int continuer=1;
    system("title OGame Stats");
    printf("\n\nCe programme va vous assister a la production de vos batiments en fonction de vos ressources.\n\n");  //Definir un tableau de planete ici et les initialiser
    input
    while(continuer)
    {PREZ
        printf("\nQue voulez vous faire ?\n");
        switch(presentation())
        {
        case 1:
            conv();
            break;
        case 2:
            attente(0);
            break;
        case 3:
            attente(1);
            break;
        case 4:
            attentemultiple(0); //0:sans lecture du fichier
            break;
        case 5:
            attentemultiple(1); //1:avec lecture du fichier
            break;
        case 42:
            continuer--;
            break;
        default:
            PREZ
            printf("\n\n\n\n\n\nErreur argument...\n\n");
            input input
            PREZ
            printf("\n\n\n\n\n\nCHOISIS ENTRE 1 ET 5 C'EST PAS DUR CONNARD !!!");
            input
            PREZ
            break;
        }
    }
    return 0;
}

int presentation()
{
    int choix=0;
    printf("1.Voir combien de temps il faut pour produire 1 minerais.\n2.Calculer le temps restant avant de pouvoir faire tel batiment.\n3.Calculer combien de minerai vous produisez en fonction du temps.\n4.Pour combien de temps les objectifs de chaque minerai seront remplis.\n5.QuickTime Checker");
    printf("\nTapez 42 pour terminer le programme.");
    printf("\nVotre choix: ");
    scanf("%d",&choix);
    return choix;
}

void conv()
{CONV
    int prod=0, systHMS[5]={0}, res=0;
    char TEMPS[20]={};
    printf("\nVeuillez entrer votre production actuelle (en minerai/heure), puis l'unite de temps voulue.\n");
    printf("\nProduction: ");
    scanf("%d",&prod);
    printf("Temps:\n\t1.Heures\n\t2.Minutes\n\t3.Secondes\n\nVotre choix: ");
    scanf("%d",&systHMS[4]);
    switch(systHMS[4])
    {
        case 1:
            systHMS[0]=1;
            TEMPS[0]='h';TEMPS[1]='e';TEMPS[2]='u';TEMPS[3]='r';TEMPS[4]='e';TEMPS[5]='(';TEMPS[6]='s';TEMPS[7]=')';
            break;
        case 2:
            systHMS[1]=1;
            TEMPS[0]='m';TEMPS[1]='i';TEMPS[2]='n';TEMPS[3]='u';TEMPS[4]='t';TEMPS[5]='e';TEMPS[6]='(';TEMPS[7]='s';TEMPS[8]=')';
            break;
        case 3:
            systHMS[2]=1;
            TEMPS[0]='s';TEMPS[1]='e';TEMPS[2]='c';TEMPS[3]='o';TEMPS[4]='n';TEMPS[5]='d';TEMPS[6]='e';TEMPS[7]='(';TEMPS[8]='s';TEMPS[9]=')';
            break;
        default:
            printf("\nErreur d'argument.");
            return;
    }
    res=(systHMS[0]*HEURE+systHMS[1]*MINUTE+systHMS[2]*SECONDE)/(prod);
    printf("\nPour produire un minerai il vous faudra %d %s.\n",res,TEMPS);
    input input
    return;
}

void attente(int mode)
{ATT
    int res=0,temps=0,prod=0,but=0,stock=0,systHMS[5]={0,0,0};
    char TEMPS[20]={0};

    if(!mode)
    {
        printf("\nVeuillez entrer la quantite de minerai necessaire, la quantite en stock, votre production actuelle (en minerai/heure), puis l'unite de temps voulue.\n");
        printf("\nMinerai necessaire: ");
        scanf("%d",&but);
        printf("Minerai en stock: ");
        scanf("%d",&stock);
        systHMS[0]=1;
    }
    else if(mode)
    {
        printf("\nVeuillez entrer le temps d'attente voulue, votre production actuelle (en minerai/heure), puis l'unite de temps voulue (dans la meme unité que le temps d'attente).\n");
        printf("\nTemps a calculer (format: chiffre h OU chiffre min OU chiffre sec: ");
        scanf("%d",&temps);
        scanf("%s",TEMPS);
        if(TEMPS[0]=='h')
            systHMS[0]=1;
        else if(TEMPS[0]=='m')
            systHMS[1]=1;
        else if(TEMPS[0]=='s')
            systHMS[2]=1;
        else {printf("Erreur argument");}
        input input
    }
    printf("Production: ");
    scanf("%d",&prod);

    res=(!mode*((SECONDE*(but-stock))/prod))+mode*(temps*(prod/(systHMS[0]*HEURE+systHMS[1]*MINUTE+systHMS[2]*SECONDE)));
    if(mode)
    {
        printf("En %d %s vous aurez produits %d minerais",temps,TEMPS,res);
    }
    else
    {
        if(res>=60&&res<=3600){
            TEMPS[0]='m';TEMPS[1]='i';TEMPS[2]='n';TEMPS[3]='u';TEMPS[4]='t';TEMPS[5]='e';TEMPS[6]='(';TEMPS[7]='s';TEMPS[8]=')';
            systHMS[2]=res%60;
            res=res/60;
            printf("\nIl vous faudra attendre %d%s%dsec.\n",res,TEMPS,systHMS[2]);}
        else if(res>=3600){
            TEMPS[0]='h';TEMPS[1]='e';TEMPS[2]='u';TEMPS[3]='r';TEMPS[4]='e';TEMPS[5]='(';TEMPS[6]='s';TEMPS[7]=')';
            systHMS[2]=res%60;
            res=res/60;
            systHMS[1]=res%60;
            res=res/60;
            printf("\nIl vous faudra attendre %d%s%dmin%dsec.\n",res,TEMPS,systHMS[1],systHMS[2]);}
        else printf("\nIl vous faudra attendre %dsec.\n",res);
    }
    input input
    return;
}

void attentemultiple(int mode)
{ATT
    planeteINFO Troglodyte=initialiserCONFIG(-1,Troglodyte); //Pre remplissage pour test: { {prod,dispo,cache,stockmax,conso,{mine,stock,cache}} , {prod,dispo,cache,stockmax,conso,{mine,stock,cache}} , {prod,dispo,cache,stockmax,conso,{mine,stock,cache}} , {prod,dispo,cache,stockmax,conso,{mine,stock,cache}} , Tmini , Tmaxi };
    float objectif[4];
    int res[4],choix;
    if(mode)
        Troglodyte=lectureFichier(0,Troglodyte);
    else
    {
        printf("\nVeuillez remplir la liste des parametres avant calcul.");
        Troglodyte=initialiserCONFIG(mode,Troglodyte);
    }
    system("cls");
    printf("Veuillez maintenant indiquer vos objectifs: ");
    printf("\nMetal a avoir: ");
    scanf("%f",&objectif[0]);
    printf("\nCristal a avoir: ");
    scanf("%f",&objectif[1]);
    printf("\nDeuterium a avoir: ");
    scanf("%f",&objectif[2]);
    printf("\nEnergie necessaire au fonctionnement: ");
    scanf("%f",&objectif[3]);
    if(Troglodyte.Energie.dispo<objectif[3])
        printf("\n\nAttention, il vous faut %.0f d'energie mais vous n'en avez que %.0f, pensez a augmenter votre production.",objectif[3],Troglodyte.Energie.dispo);

    res[0]=ceil(((SECONDE*(objectif[0]-Troglodyte.Metal.dispo))/Troglodyte.Metal.prod));
    if(res[0]>=60&&res[0]<=3600)
        printf("\n\nIl vous faudra attendre %dmin%dsec pour avoir assez de metal.",res[0]/60,res[0]%60);
    else if(res[0]>=3600)
        printf("\n\nIl vous faudra attendre %dh%dmin%dsec pour avoir assez de metal.",res[0]/3600,(res[0]/60)%60,res[0]%60);
    else if(res[0]>0&&res[0]<60) printf("\n\nIl vous faudra attendre %dsec pour avoir assez de metal.",res[0]);

    res[1]=ceil(((SECONDE*(objectif[1]-Troglodyte.Cristal.dispo))/Troglodyte.Cristal.prod));
    if(res[1]>=60&&res[1]<=3600)
        printf("\nIl vous faudra attendre %dmin%dsec pour avoir assez de cristal.",res[1]/60,res[1]%60);
    else if(res[1]>=3600)
        printf("\nIl vous faudra attendre %dh%dmin%dsec pour avoir assez de cristal.",res[1]/3600,(res[1]/60)%60,res[1]%60);
    else if(res[1]>0&&res[1]<60)printf("\nIl vous faudra attendre %dsec pour avoir assez de cristal.",res[1]);

    res[2]=ceil(((SECONDE*(objectif[2]-Troglodyte.Deuterium.dispo))/Troglodyte.Deuterium.prod));
    if(res[2]>=60&&res[2]<=3600)
        printf("\nIl vous faudra attendre %dmin%dsec pour avoir assez de deuterium.",res[2]/60,res[2]%60);
    else if(res[2]>=3600)
        printf("\nIl vous faudra attendre %dh%dmin%dsec pour avoir assez de deuterium.",res[2]/3600,(res[2]/60)%60,res[2]%60);
    else if(res[2]>0&&res[2]<60)printf("\nIl vous faudra attendre %dsec pour avoir assez de deuterium.",res[2]);

    input input

    printf("\nVoulez vous sauvegarder les données ?\n1.Oui\n2.Non\nVotre choix: ");
    scanf("%d",&choix);

    if(choix==1)
        lectureFichier(1,Troglodyte);

    return;
}

planeteINFO initialiserCONFIG(int mode,planeteINFO planete)
{
    if(mode==-1)
    {
        planeteINFO planete_basique={ {60,0,0,20000,0,{0,0,0}} , {30,0,0,20000,0,{0,0,0}} , {0,0,0,20000,0,{0,0,0}} , {0,0,0,0,0,{0,0,0}} , 0 , 0 };
        return planete_basique;
    }
    else
    {
        if(!mode)
        {
            printf("\nEntrez la temperature maximale de votre planete: ");
            scanf("%d",&planete.Tmaxi);

            printf("\n\nMetal:\nEntrez le niveau de vos mines de metal: ");
            scanf("%d",&planete.Metal.niveau.mine);
            printf("Entrez le niveau de votre hangar de metal: ");
            scanf("%d",&planete.Metal.niveau.stock);
            printf("Entrez le niveau de votre cachette de metal camouflee: ");
            scanf("%d",&planete.Metal.niveau.cache);
            printf("Et pour finir, entrez la quantite de metal que vous avec a disposition: ");
            scanf("%f",&planete.Metal.dispo);
            planete.Metal.prod=vit_uni*(30+ceil(30*(planete.Metal.niveau.mine)*pow(1.1,planete.Metal.niveau.mine)));
            planete.Metal.conso=ceil(10*(planete.Metal.niveau.mine)*pow(1.1,planete.Metal.niveau.mine));
            planete.Metal.stockmax=5000*floor(2.5*pow(2.71828,20*(planete.Metal.niveau.stock)/33));
            planete.Metal.cache=floor(2089.321352*2*pow(planete.Metal.niveau.cache,0.8));

            printf("\n\nCristal:\nEntrez le niveau de vos mines de cristal: ");
            scanf("%d",&planete.Cristal.niveau.mine);
            printf("Entrez le niveau de votre hangar de cristal: ");
            scanf("%d",&planete.Cristal.niveau.stock);
            printf("Entrez le niveau de votre cachette de cristal souterraine: ");
            scanf("%d",&planete.Cristal.niveau.cache);
            printf("Et pour finir, entrez la quantite de cristal que vous avec a disposition: ");
            scanf("%f",&planete.Cristal.dispo);
            planete.Cristal.prod=vit_uni*(15+ceil(20*(planete.Cristal.niveau.mine)*pow(1.1,planete.Cristal.niveau.mine)));
            planete.Cristal.conso=ceil(10*(planete.Cristal.niveau.mine)*pow(1.1,planete.Cristal.niveau.mine));
            planete.Cristal.stockmax=5000*floor(2.5*pow(2.71828,20*(planete.Cristal.niveau.stock)/33));
            //planete.Cristal.cache=floor(2089.321352*pow(planete.Cristal.niveau.cache,0.8));   NON RENSEIGNE

            printf("\n\nDeuterium:\nEntrez le niveau de vos synthetiseurs de deuterium: ");
            scanf("%d",&planete.Deuterium.niveau.mine);
            printf("Entrez le niveau de votre reservoir de deuterium: ");
            scanf("%d",&planete.Deuterium.niveau.stock);
            printf("Entrez le niveau de votre cachette de deuterium sous-marine: ");
            scanf("%d",&planete.Deuterium.niveau.cache);
            printf("Et pour finir, entrez la quantite de deuterium que vous avec a disposition: ");
            scanf("%f",&planete.Deuterium.dispo);
            planete.Deuterium.prod=vit_uni*ceil((10*(planete.Deuterium.niveau.mine)*pow(1.1,planete.Deuterium.niveau.mine))*(-0.004*planete.Tmaxi+1.44));
            planete.Deuterium.conso=ceil(20*(planete.Deuterium.niveau.mine)*pow(1.1,planete.Deuterium.niveau.mine));
            planete.Deuterium.stockmax=100000+50000*floor(pow(1.6,planete.Deuterium.niveau.stock));
            //planete.Deuterium.cache=floor(2089.321352*pow(planete.Deuterium.niveau.cache,0.8));   NON RENSEIGNE

            printf("\n\nEnergie:\nEntrez votre production energetique: ");
            scanf("%f",&planete.Energie.prod);
            planete.Energie.conso=planete.Metal.conso+planete.Cristal.conso+planete.Deuterium.conso;
            planete.Energie.dispo=planete.Energie.prod-(planete.Energie.conso);
            if(planete.Energie.dispo<planete.Deuterium.conso/1.5)
                printf("Attention, vous avez n'avez plus que %.0f energie disponible!",planete.Energie.dispo);
            else
                printf("Vous avez %.0f energie disponible.",planete.Energie.dispo);

            input input

        }
        return planete;
    }

}

planeteINFO lectureFichier(int mode,planeteINFO planete)  //Proposer d'enregistrer les données dans un .txt, le QuickTime Checker rechargera les dernières données (et ce .txt pourra etre rempli manuellement)
{
    FILE* fichier=NULL;
    if(mode)
    {
        fichier=fopen("OgameSAVE.OGS","w+");  //Ecrire
        fprintf(fichier,"En développement");
    }
    else
    {
        //Lire
    }

    return planete;
}
