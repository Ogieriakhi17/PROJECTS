// <copyright file="MainWindow.axaml.cs" company="Osaze Ogieriakhi 11784953">
// Copyright (c) Osaze Ogieriakhi 11784953. All rights reserved.
// </copyright>

namespace Spreadsheet_Osaze_Ogieriakhi.Views;

using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Linq;
using System.Reactive.Linq;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Templates;
using Avalonia.Data;
using Avalonia.Media;
using Avalonia.ReactiveUI;
using ReactiveUI;
using Spreadsheet_Osaze_Ogieriakhi.ViewModels;
using SpreadsheetEngine;

public partial class MainWindow : ReactiveWindow<MainWindowViewModel>
{
    /// <summary>
    /// Initializes a new instance of the <see cref="MainWindow"/> class.
    /// </summary>
    public MainWindow()
    {
        InitializeComponent();

       // DataGrid dataGrid = this.FindControl<DataGrid>("dataGrid");
        DataContextChanged += (sender, args) =>
        {
            if (this.DataContext is MainWindowViewModel viewModel)
            {
                viewModel.InitializeDataGrid(this.SpreadsheetDataGrid);
            }
        };
    }
}
