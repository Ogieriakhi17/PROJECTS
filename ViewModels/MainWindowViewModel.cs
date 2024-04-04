// <copyright file="MainWindowViewModel.cs" company="Osaze Ogieriakhi">
// Copyright (c) Osaze Ogieriakhi. All rights reserved.
// </copyright>

namespace Spreadsheet_Osaze_Ogieriakhi.ViewModels;

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Linq;
using Avalonia;
using Avalonia.Controls;
using Avalonia.Controls.Templates;
using Avalonia.Data;
using Avalonia.Layout;
using Avalonia.Media;
using ReactiveUI;
using Spreadsheet_Osaze_Ogieriakhi.Views;
using SpreadsheetEngine;

/// <inheritdoc />
public class MainWindowViewModel : ViewModelBase
{
    private readonly Spreadsheet demo;

    public AbstractCell[][] Rows { get; }

    private bool isInitialized;

    public void InitializeDataGrid(DataGrid dataGrid)
    {
        if (this.isInitialized) return;

        // initialize A to Z columns headers since these are indexed this is not a behavior supported by default
        var columnCount = 'Z' - 'A' + 1;
        foreach (var columnIndex in Enumerable.Range(0, columnCount))
        {
            // for each column we will define the header text and
            // the binding to use
            var columnHeader = (char)('A' + columnIndex);
            var columnTemplate = new DataGridTemplateColumn
            {
                Header = columnHeader,
                CellTemplate = new FuncDataTemplate<IEnumerable<AbstractCell>>((value, namescope) =>
                    new TextBlock
                    {
                        [!TextBlock.TextProperty] =
                            new Binding($"[{columnIndex}].Value"),
                        TextAlignment = TextAlignment.Left,
                        VerticalAlignment = VerticalAlignment.Center,
                        Padding = Thickness.Parse("5,0,5,0")
                    }),
                CellEditingTemplate = new FuncDataTemplate<IEnumerable<AbstractCell>>((value, namescope) =>
                    new TextBox
                    {
                        [!TextBox.TextProperty] = new Binding($"[{columnIndex}].Text")
                    }),
            };
            dataGrid.Columns.Add(columnTemplate);
        }

        dataGrid.ItemsSource = this.Rows;
        dataGrid.LoadingRow += (sender, args) => { args.Row.Header = (args.Row.GetIndex() + 1).ToString(); };

        isInitialized = true;
    }

    public MainWindowViewModel()
    {

        demo = new Spreadsheet(50, 26);

        this.Rows = Enumerable.Range(0, demo.RowCount)
            .Select(row => Enumerable.Range(0, demo.ColumnCount)
                .Select(column => this.demo.GetCell(row, column)).ToArray())
            .ToArray();
        
        demo.SpreadsheetPropertyChanged += OnSpreadsheetPropertyChanged;
    }
    /// <summary>
    /// Updates the cells that have a reference to the CellName
    /// </summary>
    /// <param name="cellName">String.</param>
    private void Update(string cellName)
    {
        // Goes through the spreadsheet
        for (int i = 0; i < 26; i++)
        {
            for (int j = 0; j < 50; j++)
            {
                // if the cells text contains the cellName, update the value
                if (demo.GetCell(j, i).Text.Contains(cellName))
                { 
                   // demo.UpdateHelper(cellName);
                }
            }
        }
    }

    private void OnSpreadsheetPropertyChanged(object? sender, PropertyChangedEventArgs e)
    {
        if (e.PropertyName.StartsWith("Cell_"))
        {
            // Extract cell indices from property name
            var indices = e.PropertyName.Split('_').Skip(1).Select(int.Parse).ToArray();
            int rowIndex = indices[0];
            int colIndex = indices[1];

            // Notify UI that the corresponding cell value has changed
            this.RaisePropertyChanged(Rows[rowIndex][colIndex].Value);

        }
    }

    public void RunDemo()
    {
        Random randomGenerator = new Random();


        demo.GetCell(0, 0).Text = "10";
        demo.GetCell(1, 0).Text = "10";
        demo.GetCell(1, 1).Text = "=A1+A2";
        
        
        // demo.GetCell(1, 0).Text = "15";
        

        /*
        foreach (var i in Enumerable.Range(0, 50))
        {
            int row = randomGenerator.Next(0, 49);
            int col = randomGenerator.Next(0, 26);
            this.demo.GetCell(row, col).Text = "here";
            //demo.UpdateHelper(demo.GetCell(row, col));
        }

        foreach (var i in Enumerable.Range(0, 49))
        {
            this.demo.GetCell(i, 1).Text = "This is Cell B" + this.Rows[i + 1][1].RowIndex;
        }

        
        foreach (var i in Enumerable.Range(0, 49))
        {
            this.demo.GetCell(i, 0).Text = "=B" + this.Rows[i + 1][1].RowIndex;
        }
        
        */
    }
}
