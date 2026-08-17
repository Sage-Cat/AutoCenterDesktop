# AutoCenterDesktop

AutoCenterDesktop is a legacy Ukrainian-language Qt 5 desktop application for a small automotive-goods business. It keeps products, stock movements, customers, sellers, vehicles, invoices, receipts, and barcode labels in a local SQLite database. It can also import supplier XML and generate printable HTML or MEDOC-oriented XML documents.

> [!WARNING]
> The bundled document templates target historical Ukrainian business workflows and are not a guarantee of current legal or tax compliance. Review generated documents before use. The application has no authentication or database encryption; protect and back up the local database if it contains personal or business data.

## Build

Install Qt 5 with the Widgets, SQL/SQLite, and Print Support modules, then run:

```sh
mkdir build
cd build
qmake ../AutoCenterDesktop/AutoCenterDesktop.pro
make -j"$(nproc)"
```

The database is created on first launch in the platform-specific application data directory (for example, `~/.local/share/AutoCenterDesktop/database.db` on Linux). Existing databases are not migrated automatically.

## Main capabilities

- Manage products, stock receipts and sales documents.
- Manage customers, sellers, and customer vehicles.
- Import Omega supplier price lists and invoices.
- Print invoices, receipts, and Code 128 barcode labels.
- Export MEDOC-oriented tax-invoice XML.

The vendored Code 128 implementation is from [Promixis/Code128](https://github.com/promixis/Code128) and retains its MIT license notice. The rest of the project is licensed under [GPL-3.0](LICENSE).
