
import csv
import matplotlib.pyplot as plt

# Listes pour stocker les données
profondeur = []
energie = []

# Lecture du fichier CSV
with open("profil_bragg.csv", "r") as fichier:
    lecteur = csv.DictReader(fichier)

    for ligne in lecteur:
        if ligne["Profondeur_cm"] and ligne["Energie_moyenne_MeV"]:
            profondeur.append(float(ligne["Profondeur_cm"]))
            energie.append(float(ligne["Energie_moyenne_MeV"]))
    print("Nombre de points lus :", len(profondeur))
    print("Profondeurs :", profondeur[:10])
    print("Énergies :", energie[:10])

# Tracé du graphique
plt.figure(figsize=(10, 6))

plt.plot(profondeur, energie, linewidth=1.5)

plt.title("Pic de Bragg – Protons de 100 MeV")
plt.xlabel("Profondeur dans l'eau (cm)")
plt.ylabel("Énergie moyenne déposée par tranche (MeV/proton)")

plt.grid(True, linestyle="--", alpha=0.5)
plt.tight_layout()

# Enregistrement et affichage
plt.savefig("graphique_bragg.png", dpi=300)
plt.show()
